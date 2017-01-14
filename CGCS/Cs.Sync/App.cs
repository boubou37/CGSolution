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
        int N = int.Parse(Console.ReadLine());
        int[] arr = new int[N];
        for (int i = 0; i < N; i++)
        {
            int pi = int.Parse(Console.ReadLine());
            arr[i] = pi;
        }
        int res = Int32.MaxValue;
        Array.Sort(arr);
        int temp;
        for (int i = 1; i < N; i++)
        {
            temp = arr[i] - arr[i-1];
            res = Math.Min(res, temp);
        }
        Console.WriteLine(res);
    }
}