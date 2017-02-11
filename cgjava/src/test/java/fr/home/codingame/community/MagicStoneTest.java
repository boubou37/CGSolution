package fr.home.codingame.community;

import junit.framework.TestCase;
import org.junit.Assert;
import org.junit.Test;

import java.io.File;
import java.net.URL;

/**
 * Created by lrhmf on 11/02/2017.
 */

public class MagicStoneTest extends TestCase {
    @Test
    public void testSolve() throws Exception {
        String cl = getClass().getClassLoader().getResource("community/magicstones/Test0.txt").getFile();
        File f = new File(cl);
        System.out.println(f);
        Assert.assertTrue(true);
    }

}