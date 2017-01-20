using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.Dev
{
    public abstract class Testable
    {
        public Testable(string cat, string name)
        {
            this.puzCategory = cat;
            this.puzName = name;
        }
        private StreamReader sr;
        private string puzCategory;
        public string PuzCategory
        {
            get
            {
                return this.puzCategory;
            }
        }
        private string puzName;
        public string PuzName
        {
            get
            {
                return this.puzName;
            }
        }

    }
}
