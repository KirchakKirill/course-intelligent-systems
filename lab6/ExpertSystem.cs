using CLIPSNET;
using System;
using System.Collections.Generic;
using System.Data;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace prodsys_clips_frame
{
    public partial class ExpertSystem : Form
    {
        private CLIPSNET.Environment clips;

        private string pathCrafts = "";
        private const string pathCLP = "crafts.clp";
        private bool targetReached = false;
        private HashSet<Rule> rules;
        private List<Fact> facts;
        private HashSet<Fact> factsIn;
        private Fact factOut;

        public ExpertSystem()
        {
            InitializeComponent();
            clips = new CLIPSNET.Environment();
            rules = new HashSet<Rule>();
            facts = new List<Fact>();
            factsIn = new HashSet<Fact>();
        }

        private void checkedListBox1_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            Fact fact = facts.Find(x => x.Title == (string)checkedListBox1.Items[e.Index]);
            if (e.NewValue == CheckState.Checked)
                factsIn.Add(fact);
            else
                factsIn.Remove(fact);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex == -1)
                return;

            factOut = facts.Where(x => x.Title == listBox1.SelectedItem.ToString()).First();
        }

        private void loadRulesButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    pathCrafts = openFileDialog.FileName;
                    LoadRules(pathCrafts);
                    GenerateCLP(pathCrafts);
                }
            }
        }

        private void LoadRules(string filePath)
        {
            string[] lines = File.ReadAllLines(filePath);
            foreach (string line in lines)
            {
                Rule r = new Rule();
                if (r.TryParse(line))
                    rules.Add(r);
            }

            foreach (Rule rule in rules)
            {
                foreach (string factIn in rule.FactsIn)
                    facts.Add(new Fact(factIn, factIn));
                facts.Add(new Fact(rule.FactOut, rule.FactOut));
            }

            facts.Sort(delegate (Fact f1, Fact f2) { return f1.Title.CompareTo(f2.Title); });

            DisplayData();
        }

        private void DisplayData()
        {
            rules.OrderBy(r => r.FactOut).ToList().ForEach(rule => { listBox1.Items.Add(rule.FactOut); });
            facts.Distinct().ToList().ForEach(facts => { checkedListBox1.Items.Add(facts.Title); });
        }

        private void InitClips()
        {
            clips.LoadFromString(File.ReadAllText(pathCLP));
        }

        private void AddButton_Click(object sender, EventArgs e)
        {
            richTextBox1.Clear();
            button3.Enabled = true;
            AddFacts();
        }

        private void AddFacts()
        {
            clips.Clear();
            InitClips();

            foreach (var fact in factsIn)
            {
                clips.Eval($"(assert (item (name {fact.ID})))");
                richTextBox1.Text += $"Добавлено: {fact.Title}\n";
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            HandleResponse();
        }

        private bool ParsePhrase(List<FactInstance> phrases)
        {
            var t = phrases[0].GetSlotValues();
            var phrase = phrases[0].GetSlotValues()[0].ToString().Trim(new char[] { '(', ')', '"' }).Split(':');
            richTextBox1.Text += $"Получено: {phrase[0]}:{phrase[1]}\n";
            clips.Eval("(assert (clearmessage))");
            return factOut.ID == phrase[0].Trim();
        }

        private void HandleResponse()
        {
            clips.Run();
            List<FactInstance> facts = clips.GetFactList();
            List<FactInstance> readyFacts = facts.Where(f => f.RelationName == "sendmessagehalt").ToList();
            bool isTarget = false;

            if (readyFacts.Count > 0)
                isTarget = ParsePhrase(readyFacts);
            clips.Eval("(assert (clear-message))");

            if (readyFacts.Count == 0 && !targetReached)
            {
                richTextBox1.Text += "Целевой факт НЕ выведен\n";
                button3.Enabled = false;
            }

            if (isTarget)
            {
                targetReached = true;
                richTextBox1.Text += "Целевой факт выведен\n";
                button3.Enabled = false;
            }
        }

        private void GenerateCLP(string filePath)
        {
            string path = System.Environment.CurrentDirectory;
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(path, pathCLP)))
            {
                string[] lines = File.ReadAllLines(filePath);

                outputFile.WriteLine(@"
(defrule clear-message
(declare (salience 90))
?clear-msg-flg <- (clearmessage)
?sendmessage <- (sendmessagehalt ?msg)
=>
(retract ?clear-msg-flg)
(retract ?sendmessage)
)
(deftemplate item
(slot name (default none))
)
                ");

                foreach (string line in lines)
                {
                    if (string.IsNullOrEmpty(line))
                        continue;

                    Rule rule = new Rule();
                    rule.TryParse(line);

                    outputFile.WriteLine($"(defrule {rule.FactOut}");

                    rule.FactsIn.ForEach(x =>
                        outputFile.WriteLine($"(item (name {x}))")
                    );

                    outputFile.WriteLine("=>");
                    outputFile.WriteLine($"(assert (item (name {rule.FactOut})))");

                    outputFile.WriteLine(
                        $"(assert (sendmessagehalt \"{rule.FactOut}:{rule.Recipe}\"))\n" +
                        $"(halt)\n" +
                        $")\n"
                        );
                }
            }
        }
    }
}
