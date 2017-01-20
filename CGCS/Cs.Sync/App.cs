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
    static string vals = "234567891JQKA";
    static void Main(string[] args)
    {
        int n = int.Parse(Console.ReadLine());
        int gr = 0;
        Queue<String> p1 = new Queue<String>();
        Queue<String> p2 = new Queue<String>();
        Queue<String> warP1 = new Queue<String>();
        Queue<String> warP2 = new Queue<String>();
        int count = 0;
        string card1 = "";
        string card2 = "";// the number of cards for player 1
        for (int i = 0; i < n; i++)
        {
            string cardp1 = Console.ReadLine();
            p1.Enqueue(cardp1);// the n cards of player 1
        }
        int m = int.Parse(Console.ReadLine()); // the number of cards for player 2
        for (int i = 0; i < m; i++)
        {
            string cardp2 = Console.ReadLine();
            p2.Enqueue(cardp2); // the m cards of player 2
        }

        while (p2.Count<String>() > 0 && p1.Count<String>() > 0)
        {
            count++;
            card1 = p1.Peek();
            card2 = p2.Peek();
            gr = Cmp(card1, card2);
            if (gr < 0)
            {
                p2.Enqueue(p1.Dequeue()); p2.Enqueue(p2.Dequeue());
            }
            else if (gr > 0)
            {
                p1.Enqueue(p1.Dequeue()); p1.Enqueue(p2.Dequeue());
            }
            else
            {
                while (gr == 0)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        warP1.Enqueue(p1.Dequeue());
                        warP2.Enqueue(p2.Dequeue());
                        if (p2.Count<String>() == 0 || p1.Count<String>() == 0)
                        {
                            Console.WriteLine("PAT");
                            Environment.Exit(0);
                        }
                    }
                    card1 = p1.Peek(); card2 = p2.Peek();
                    gr = Cmp(card1, card2);
                }
                if (gr < 0)
                {
                    transfer(warP1, ref p2);
                    p2.Enqueue(p1.Dequeue());
                    transfer(warP2, ref p2);
                    p2.Enqueue(p2.Dequeue());
                }
                else if (gr > 0)
                {
                    transfer(warP1, ref p1);
                    p1.Enqueue(p1.Dequeue());
                    transfer(warP2, ref p1);
                    p1.Enqueue(p2.Dequeue());
                }
                warP1.Clear();
                warP2.Clear();

            }
        }
        int winner = p1.Count() > 0 ? 1 : 2;
        Console.WriteLine(winner + " " + count);
    }

    static int Cmp(string card1, string card2)
    {
        int ret = vals.IndexOf(card1[0]) - vals.IndexOf(card2[0]);
        return ret;
    }

    static void transfer(Queue<string> from, ref Queue<string> to)
    {
        while (from.Count() > 0)
        {
            to.Enqueue(from.Dequeue());
        }
    }
}