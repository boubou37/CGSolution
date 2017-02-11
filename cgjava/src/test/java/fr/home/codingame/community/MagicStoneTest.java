package fr.home.codingame.community;

import fr.home.codingame.TestInitializer;
import junit.framework.TestCase;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

import java.io.File;
import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 11/02/2017.
 */

public class MagicStoneTest extends TestCase {

    List<Scanner> testInputs;

    @BeforeClass
    public void loadStreamReaders() throws Exception {
        testInputs = TestInitializer.getTestsInput("community","magicstones");
    }

    @AfterClass
    public void clearReaders() {
        for (Scanner ti : testInputs) {
            ti.close();
        }
    }

    @Test
    public void testSolve() throws Exception {
        String cl = getClass().getClassLoader().getResource("community/magicstones/Test0.txt").getFile();
        File f = new File(cl);
        System.out.println(f);
        Assert.assertTrue(true);
    }

}