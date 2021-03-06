using System;
using System.Resources;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using Cs.Dev;

public class Anagram : Testable
{
    public Anagram(string cat, string name) : base(cat, name)
    {
    }

    public string Decypher(string phrase)
    {
        string ret = UnscrambleStep4(phrase);
        Console.WriteLine(phrase);
        for (int i = 4; i >= 2; i--)
        {
            ret = UnscrambleShift(ret, i);
            Console.WriteLine(phrase);
        }
        return ret;
    }

    public string UnscrambleStep4(string sentence)
    {
        string[] toks = sentence.Split(' ');
        string cpy = sentence.Replace(" ", string.Empty);
        int[] len = new int[toks.Length];
        for (int i = 0; i < len.Length; i++)
        {
            len[i] = toks[i].Length;
        }
        Array.Reverse(len);
        int cnt = len[0]; ;
        for (int i = 1; i < len.Length; i++)
        {
            cpy = cpy.Insert(cnt++, " ");
            cnt += len[i];
        }
        return cpy;
    }

    public string UnscrambleShift(string sentence, int mod)
    {
        List<Char> chars = new List<Char>();
        char[] ret = sentence.ToCharArray();
        int count = 0;
        foreach (char c in ret)
        {
            if (c != ' ')
                if ((Convert.ToByte(c) - 64) % mod == 0)
                {
                    chars.Add(c);
                }
        }
        if (chars.Count > 0)
        {
            char[] match = chars.ToArray();
            char[] cmpMatch = (char[])match.Clone();
            switch (mod)
            {
                case 2:
                    Array.Reverse(cmpMatch);
                    break;
                case 3:
                    cmpMatch[cmpMatch.Length - 1] = cmpMatch[0];
                    Array.Copy(match, 1, cmpMatch, 0, match.Length - 1);
                    break;
                case 4:
                    cmpMatch[0] = cmpMatch[cmpMatch.Length - 1];
                    Array.Copy(match, 0, cmpMatch, 1, match.Length - 1);
                    break;
                default: break;
            }
            for (int i = 0; i < ret.Length; i++)
            {
                if (match[count] == ret[i])
                {
                    ret[i] = cmpMatch[count++];
                    if (count == match.Length) break;
                }
            }
        }
        return new string(ret);
    }

}