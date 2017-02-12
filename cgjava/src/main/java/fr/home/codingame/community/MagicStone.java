package fr.home.codingame.community;

import fr.home.codingame.ICodinGame;

import java.util.*;

/**
 * Created by lrhmf on 11/02/2017.
 */
public class MagicStone implements ICodinGame<Integer> {

    public Integer solve(Scanner in) {
        int N = in.nextInt();
        Set<Integer> l = new HashSet<Integer>();
        for (int i = 0; i < N; i++) {
            int level = in.nextInt();
            setAdd(l,level);
        }
        return l.size();
    }

    public boolean setAdd(Set<Integer> set, int val) {
        if (set.add(val)) {
            return true;
        }
        else {
            set.remove(val);
            return setAdd(set,val+1);
        }
    }

}
