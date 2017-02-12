import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        int a = 1;
        int b = a ^1;
        System.out.println(b);

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