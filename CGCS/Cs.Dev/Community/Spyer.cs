using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.Dev.Community
{
    class Spyer
    {
        static void Main(string[] args)
        {
            List<string> l = new List<string>();
            l.Add("brutus");
            l.Add("tin");
            l.Add("rintintin");
            var v = l.Where(x => x.Length > 3).ToArray();
            Console.WriteLine(v.Length);
        }
    }

    class Suspect
    {
        private string name;
    }
}
