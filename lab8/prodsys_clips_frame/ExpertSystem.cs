using CLIPSNET;
using System;
using System.Collections.Generic;
using System.Data;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace prodsys_clips_frame
{
    public partial class ExpertSystem : Form
    {
        private CLIPSNET.Environment clips;

        private string pathCrafts = "";
        private const string pathCLP = "crafts.clp";
        private bool targetReached = false;
        private static HashSet<Rule> rules;
        private static  List<Fact> facts;
        private List<Fact> factsIn;
        private Fact factOut;
        private static List<string> allFactOut;

        internal static HashSet<Rule> Rules { get => rules; set => rules = value; }
        internal static List<Fact> Facts { get => facts; set => facts = value; }
        internal static List<string> AllFactOut { get => allFactOut; set => allFactOut = value; }

        public ExpertSystem()
        {
            InitializeComponent();
            clips = new CLIPSNET.Environment();
            rules = new HashSet<Rule>();
            facts = new List<Fact>();
            factsIn = new List<Fact>();
            allFactOut = new List<string>();
        }

        private void checkedListBox1_ItemCheck(object sender, ItemCheckEventArgs e)
        {
            Fact fact = facts.Find(x => x.name == (string)checkedListBox1.Items[e.Index]);
            if (e.NewValue == CheckState.Checked)
                factsIn.Add(fact);
            else
                factsIn.Remove(fact);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listBox1.SelectedIndex == -1)
                return;

            factOut = facts.Where(x => x.name == listBox1.SelectedItem.ToString()).First();
        }

        private void loadRulesButton_Click(object sender, EventArgs e)
        {
            using (OpenFileDialog openFileDialog = new OpenFileDialog())
            {
                openFileDialog.Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";

                if (openFileDialog.ShowDialog() == DialogResult.OK)
                {
                    pathCrafts = openFileDialog.FileName;
                    
                    GenerateCLP(pathCrafts);
                }
            }
        }


        private void DisplayData()
        {
            Rules.OrderBy(r => r.FactOut.name).ToList().ForEach(rule => { listBox1.Items.Add(rule.FactOut.name); });
            facts.Distinct().ToList().ForEach(facts => { checkedListBox1.Items.Add(facts.name); });
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
                
                clips.Eval($"(assert (item (name {fact.name}) (confidence {fact.confidence})))");
                richTextBox1.Text += $"Добавлено: {fact.name}\n";
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
            HashSet<Fact> FactsInHashSet = new HashSet<Fact>(Facts);
            var Confidence_FactOut = FactsInHashSet.Where(x => x.name == phrase[0]).First();
            string s = string.Join(String.Empty, phrase[1].TakeWhile(y => y != '='));
            var Confidence_FactsIn = FactsInHashSet.Where(x => s.Split('+').Contains(x.name)).ToList();
            richTextBox1.Text += $"Получено: {Confidence_FactOut.name} ({Confidence_FactOut.confidence}):";
            int length = Confidence_FactsIn.Count();
            for (int i = 0; i < length; i++)
            {
                if (i + 1 == length)
                {
                    richTextBox1.Text += $"{Confidence_FactsIn[i].name} ({Confidence_FactsIn[i].confidence}) \n";
                    break;
                }
                richTextBox1.Text += $"{Confidence_FactsIn[i].name} ({Confidence_FactsIn[i].confidence})+";
            }

            clips.Eval("(assert (clearmessage))");
            return factOut.name == phrase[0].Trim();
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
            System.Threading.Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en-US");
            using (StreamWriter outputFile = new StreamWriter(Path.Combine(path, pathCLP)))
            {
                string[] lines = File.ReadAllLines(filePath);
                AllFactOut.AddRange(lines.Select(x => x.Split('=')[1]));

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
(slot name (default none)) (slot confidence (type FLOAT))
)
                ");
                Rule.Lines = lines;
                for (int i = 0; i < lines.Length; i++)
                {
                    if (string.IsNullOrEmpty(lines[i]))
                        continue;

                    Rule.FillRules(lines[i],i);
                   
                }
                foreach (Rule rule in Rules)
                {
                    outputFile.WriteLine($"(defrule {rule.FactOut.name}");

                    rule.FactsIn.ForEach(x =>
                    {
                        outputFile.WriteLine($"(item (name {x.name}) (confidence {(float)x.confidence}))");
                    }


                    );
                    outputFile.WriteLine("=>");
                    outputFile.WriteLine($"(assert (item (name {rule.FactOut.name}) (confidence {(float)rule.FactOut.confidence})))");

                    outputFile.WriteLine(
                        $"(assert (sendmessagehalt \"{rule.FactOut.name}:{rule.Recipe}\"))\n" +
                        $"(halt)\n" +
                        $")\n"
                        );
                }
                
                
            }
            Facts.Sort(delegate (Fact f1, Fact f2) { return f1.name.CompareTo(f2.name); });
            DisplayData();
        }
    }
}
