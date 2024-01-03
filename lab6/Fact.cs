using System.Collections.Generic;
using System.Linq;

namespace prodsys_clips_frame
{
    internal class Fact
    {
        public string ID { get; }
        public string Title { get; }
        public Fact(string id, string title)
        {
            ID = id;
            Title = title;
        }

        public override bool Equals(object obj)
        {
            return obj is Fact fact &&
                   ID == fact.ID &&
                   Title == fact.Title;
        }

        public override int GetHashCode()
        {
            int hashCode = 1831404553;
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(ID);
            hashCode = hashCode * -1521134295 + EqualityComparer<string>.Default.GetHashCode(Title);
            return hashCode;
        }
    }
}
