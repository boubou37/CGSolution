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
        int N = in.nextInt();
        Set<Integer> set = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            int level = in.nextInt();
            setAdd(set,level);
        }
        System.out.println(set.size());
    }

    public static boolean setAdd(Set<Integer> set, int val) {
        if (set.add(val)) {
            return true;
        }
        else {
            set.remove(val);
            return setAdd(set,val+1);
        }
    }

}