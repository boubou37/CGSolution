package fr.home.codingame.community;

import fr.home.codingame.ICodinGame;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 12/02/2017.
 */
public class MinimumSwap implements ICodinGame<Integer> {

    @Override
    public Integer solve(Scanner in) {
        int n = in.nextInt();
        List<Integer> l = new ArrayList<Integer>();
        int firstZero, lastOne;
        int count = 0;
        for (int i = 0; i < n; i++) {
            int x = in.nextInt();
            l.add(x);
        }
        do {
            firstZero = l.indexOf(0);
            lastOne = l.lastIndexOf(1);
            if (firstZero < lastOne && firstZero >= 0) {
                l.set(firstZero, 1);
                l.set(lastOne, 0);
                count++;
            }
        }  while (l.indexOf(0) < l.lastIndexOf(1) && l.indexOf(0) >= 0);
        printList(l);
        return count;
    }

    public void printList(List<Integer> l) {
        for (Integer i : l) {
            System.out.print(i + " ");
        }
    }

}
