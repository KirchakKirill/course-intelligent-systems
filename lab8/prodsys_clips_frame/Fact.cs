using System;
using System.Collections.Generic;
using System.Linq;
using System.Security.Authentication;

namespace prodsys_clips_frame
{
    internal class Fact
    {
        private static Random r = new Random();
        public string name{ get; }
        public float confidence { get; set; }
        public Fact(string name)
        {
            
            this.name = name;
            confidence = (float)r.NextDouble();

        }

        public Fact()
        {

        }

      
        public override bool Equals(object obj)
        {
            return obj is Fact fact &&
                   name == fact.name;
        }

        public override int GetHashCode()
        {
            int hashCode = 1831404553;
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(name);
            return hashCode;
        }
    }
}
