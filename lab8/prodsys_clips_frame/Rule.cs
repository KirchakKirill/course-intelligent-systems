using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Net;

namespace prodsys_clips_frame
{
    internal class Rule
    {
        public string Recipe { get; set; }
        public List<Fact> FactsIn { get; set; }
        public Fact FactOut { get; set; }
        
        public static string[] Lines { get; set; }
        public Rule()
        {
            Recipe = "";
            FactsIn = new List<Fact>();
            
            
        }
        public Rule(string recipe, List<Fact> factsIn, Fact factOut)
        {
            Recipe = recipe;
            FactsIn = factsIn;
            FactOut = factOut;
        }

        public static void  FillRules(string line,int index)
        {
            
            Rule rule = new Rule(); 
            rule.TryParse(line);
            ExpertSystem.Rules.Add(rule);
        }

        public Fact[] Recreate(string[] s)
        {
            Fact[] facts = new Fact[s.Length];
            for (int i = 0; i < s.Length; i++)
            {
                if (ExpertSystem.AllFactOut.Contains(s[i]))
                {
                    var ind = ExpertSystem.AllFactOut.IndexOf(s[i]);
                    FillRules(Lines[ind],ind);
                }
                var f = ExpertSystem.Facts.Where(x => x.name == s[i]);
                if (f.Count()>0)
                {
                    facts[i] = f.First();
                }
                else
                {
                    facts[i] = new Fact(s[i].Trim());
                    ExpertSystem.Facts.Add(facts[i]);
                }
                
                
            }
            return facts;
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
            FactsIn.AddRange(Recreate(t[0].Split('+')));
            FactOut = new Fact(t[1]);
            FactOut.confidence = (float)(FactsIn.Aggregate(0.0, (s, x) => s + x.confidence) / FactsIn.Count);
            ExpertSystem.Facts.Add(FactOut);
            Recipe = Recipe.Trim();
           

            return true;
        }
        
    }
}
