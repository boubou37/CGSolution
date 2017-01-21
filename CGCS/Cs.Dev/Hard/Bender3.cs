using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using Extre
using System.Text;
using System.Threading.Tasks;

namespace Cs.Dev.Hard
{
    public class Bender3 : Testable
    {
        public Bender3(string cat, string name) : base(cat, name)
        {
        }

        public string FindComplexity(StreamReader streamReader)
        {
            int N = int.Parse(streamReader.ReadLine());
            int[,] results = new int[N,2];

            for (int i = 0; i < N; i++)
            {
                string[] inputs = streamReader.ReadLine().Split(' ');
                results[i,0] = int.Parse(inputs[0]);
                results[i,1] = int.Parse(inputs[1]);
            }

            return "";
        }
    }
}
