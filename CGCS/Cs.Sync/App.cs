using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution
{
    static int[] vals = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
    static void Main(string[] args)
    {
        string ret = "";
        Dictionary<string, int> wordVal = new Dictionary<string, int>();
        int N = int.Parse(Console.ReadLine());
        for (int i = 0; i < N; i++)
        {
            string W = Console.ReadLine();
            wordVal.Add(W, W.Select(x => vals[x - 'a']).Sum());
        }
        string LETTERS = Console.ReadLine();
        ret = wordVal.Where(x => Compatible(LETTERS, x.Key)).OrderByDescending(x => x.Value).First().Key;
        Console.WriteLine(ret);
    }

    static bool Compatible(string dict, string word)
    {
        bool ret = word.All(x => dict.Count(y => y == x) >= word.Count(y => y == x));
        return ret;
    }
}