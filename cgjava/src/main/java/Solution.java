import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        List<Integer> l = new ArrayList<Integer>();
        int firstZero, lastOne;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            l.add(x);
        }
        if (!l.contains(0)) count = 0;
        else
        do {
            firstZero = l.indexOf(0);
            lastOne = l.lastIndexOf(1);
            if (firstZero < lastOne ) {
                l.set(firstZero, 1);
                l.set(lastOne, 0);
                count++;
            }
        }  while (l.indexOf(0) < l.lastIndexOf(1));
        // Write an action using System.out.println()
        // To debug: System.err.println("Debug messages...");

        System.out.println(count);
    }
}