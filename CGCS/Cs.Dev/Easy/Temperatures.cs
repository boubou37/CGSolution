using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.Dev.Easy
{
    public class Temperatures : Testable
    {
        public Temperatures(string cat, string name) : base(cat, name)
        {
        }

        public int getMinTemp(StreamReader sr)
        {
            int n = int.Parse(sr.ReadLine()); // the number of temperatures to analyse
            string temps = sr.ReadLine(); // the n temperatures expressed as integers ranging from -273 to 5526
            int min = int.MaxValue;
            if (temps.Equals(""))
            {
                min = 0;
            }
            else
            {
                var numTemps = temps.Split(' ').Select(x => int.Parse(x));
                foreach (var m in numTemps)
                {
                    if (Math.Abs(m) <= Math.Abs(min))
                    {
                        min = m == -min ? Math.Max(m, min) : m;
                    }
                }
            }
            return min;
        }
    }
}
