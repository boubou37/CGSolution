using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.Solved
{
    class Test
    {
        static void Main(string[] args)
        {
            Dictionary<string, int> te = new Dictionary<string, int>()
            {
                {"couu",25 },
                {"beee",13 },
                {"aaaaa",25 }
            };
            var v = "which";
            var y = "hicquwh";
            var z = v.Distinct();
            Console.WriteLine(string.Join("",v.Distinct()));
        }
    }
}
