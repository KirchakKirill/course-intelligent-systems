using System.Collections.Generic;

namespace prodsys_clips_frame
{
    internal class Rule
    {
        public string Recipe { get; set; }
        public List<string> FactsIn { get; set; }
        public string FactOut { get; set; }
        public Rule()
        {
            Recipe = "";
            FactsIn = new List<string>();
            FactOut = "";
        }
        public Rule(string recipe, List<string> factsIn, string factOut)
        {
            Recipe = recipe;
            FactsIn = factsIn;
            FactOut = factOut;
        }

        public override bool Equals(object obj)
        {
            return obj is Rule rule &&
                   Recipe == rule.Recipe;
        }

        public override int GetHashCode()
        {
            int hashCode = -151571485;
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Recipe);
            return hashCode;
        }

        public bool TryParse(string line)
        {
            if (string.IsNullOrEmpty(line))
                return false;

            Recipe = line;
            string[] t = line.Split('=');
            FactsIn.AddRange(t[0].Split('+'));
            FactOut = t[1];

            RemoveSpaces();

            return true;
        }
        private void RemoveSpaces()
        {
            for (int i = 0; i < FactsIn.Count; i++)
                FactsIn[i] = FactsIn[i].Trim();

            Recipe = Recipe.Trim();
        }
    }
}
