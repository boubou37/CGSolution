using System;
using System.Linq;
using System.IO;
using System.Text;
using System.Collections;
using System.Collections.Generic;

class Player
{
    static void Main(string[] args)
    {

        // game loop
        while (true)
        {
            int ind = 0;
            Dictionary<int, int> vals = new Dictionary<int, int>();
            for (int i = 0; i < 8; i++)
            {
                vals.Add(i, int.Parse(Console.ReadLine()));
            }
            Console.WriteLine(vals.OrderByDescending(x=>x.Value).FirstOrDefault().Key);
        }
    }
}