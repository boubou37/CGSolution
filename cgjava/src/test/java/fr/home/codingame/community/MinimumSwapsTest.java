package fr.home.codingame.community;

import fr.home.codingame.TestInitializer;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

import java.io.FileNotFoundException;
import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 12/02/2017.
 */
public class MinimumSwapsTest {

    private MinimumSwap ms = new MinimumSwap();
    static List<Scanner> testInputs;

    @BeforeClass
    public static void init() throws FileNotFoundException {
        testInputs = TestInitializer.getTestsInput("community","swaps");
    }

    @Test
    public void test0_Example() throws Exception {
        Scanner sc = testInputs.get(0);
        int result = ms.solve(sc);
        Assert.assertEquals(1,result);
    }
    @Test
    public void test1() throws Exception {
        Scanner sc = testInputs.get(1);
        int result = ms.solve(sc);
        Assert.assertEquals(2,result);
    }
    @Test
    public void test2() throws Exception {
        Scanner sc = testInputs.get(2);
        int result = ms.solve(sc);
        Assert.assertEquals(0,result);
    }
    @Test
    public void test3() throws Exception {
        Scanner sc = testInputs.get(3);
        int result = ms.solve(sc);
        Assert.assertEquals(5,result);
    }
    @Test
    public void test4() throws Exception {
        Scanner sc = testInputs.get(4);
        int result = ms.solve(sc);
        Assert.assertEquals(24,result);
    }
    @Test
    public void test5() throws Exception {
        Scanner sc = testInputs.get(5);
        int result = ms.solve(sc);
        Assert.assertEquals(121,result);
    }


}
