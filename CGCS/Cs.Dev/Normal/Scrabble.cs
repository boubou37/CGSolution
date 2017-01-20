using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.Dev.Normal
{
    public class Scrabble : Testable
    {
        public Scrabble(string cat, string name) : base(cat, name)
        {
        }

        int[] vals = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
        public string BestWord(StreamReader streamReader)
        {
            string ret = "";
            Dictionary<string, int> wordVal = new Dictionary<string, int>();
            int N = int.Parse(streamReader.ReadLine());
            for (int i = 0; i < N; i++)
            {
                string W = streamReader.ReadLine();
                wordVal.Add(W, W.Select(x => vals[x - 'a']).Sum());
            }
            string LETTERS = streamReader.ReadLine();
            ret = wordVal.Where(x => Compatible(LETTERS, x.Key)).OrderByDescending(x => x.Value).First().Key;
            return ret;
        }

        Boolean Compatible(string dict, string word)
        {
            //var ret = string.Join("",word.Distinct()).All(x => dict.Count(y => y == x) >= word.Count(y => y == x));
            var ret = word.All(x => dict.Count(y => y == x) >= word.Count(y => y == x));
            return ret;
        }
    }
}
