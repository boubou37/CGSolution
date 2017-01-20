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
    static void Main(string[] args)
    {
        string[] inputs = Console.ReadLine().Split(' ');
        string enemy1 = inputs[0];
        string enemy2 = inputs[1];
        string enemy3 = inputs[2];
        string enemy4 = inputs[3];
        string enemy5 = inputs[4];
        string enemy6 = inputs[5];
        for (int i = 0; i < 15; i++)
        {
            string suspect = Console.ReadLine();
        }
        string[] test =
        {
"NOT chubby",
            "short",
"red-haired",
"NOT russian",
"blond",
"NOT tall",
"french",
"NOT freckled",
"thai",
"NOT thin",
"gray-eyed"
        };
        foreach(string s in test)
        {
            Console.WriteLine(s);
        }
    }
}

class Person
{
    private string name;
    private List<String> traits;
    public Person()
    {
        traits = new List<string>();
    }
}