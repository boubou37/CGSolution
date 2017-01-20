using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Solution
{
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine()); // the number of temperatures to analyse
        string temps = Console.ReadLine(); // the n temperatures expressed as integers ranging from -273 to 5526
        int min = int.MaxValue;
        if (temps.Equals("")) min = 0;
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
        Console.WriteLine(min);
    }
}