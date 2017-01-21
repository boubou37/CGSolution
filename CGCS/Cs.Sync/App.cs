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
    static Dictionary<Node, int> cache = new Dictionary<Node, int>();
    static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        var nodes = Enumerable.Range(0, N).Select((x, y) => new Node(y, 0)).ToList();
        Node exit = new Node(-1, 0);
        string[] line;
        for (int i = 0; i < N; i++)
        {
            string room = Console.ReadLine();
            line = room.Split(' ');
            nodes[i].Weight = int.Parse(line[1]);
            nodes[i].AddChild(line[2] == "E" ? exit : nodes[int.Parse(line[2])]);
            nodes[i].AddChild(line[3] == "E" ? exit : nodes[int.Parse(line[3])]);
        }
        int res = findMax(nodes[0]);
        Console.WriteLine(res);
    }

    static int findMax(Node node)
    {
        if (node.Id < 0) return 0;
        int res = 0;
        int cached = 0;
        foreach (Node n in node.Children)
        {
            if (!cache.TryGetValue(node, out cached))
                res = Math.Max(res, node.Weight + findMax(n));
            else
                res = Math.Max(res, cached);
        }
        cache[node] = res;
        return res;
    }
}

class Node
{
    public int Weight { get; set; }
    public int Id { get; set; }
    public List<Node> Children { get; set; }

    public Node(int Id, int Weight)
    {
        this.Id = Id;
        this.Weight = Weight;
        this.Children = new List<Node>();
    }

    public void AddChild(Node n)
    {
        this.Children.Add(n);
    }
}