package fr.home.codingame.community;

import fr.home.codingame.TestInitializer;
import org.junit.AfterClass;
import org.junit.Assert;
import org.junit.BeforeClass;
import org.junit.Test;

import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 2/15/17.
 */
public class GravityTest {

    Gravity ms = new Gravity();
    private static List<Scanner> testInputs;

    @BeforeClass
    public static void loadStreamReaders() throws Exception {
        testInputs = TestInitializer.getTestsInput("community","magicstones");
    }

    @AfterClass
    public static void clearReaders() {
        for (Scanner ti : testInputs) {
            ti.close();
        }
    }

    @Test
    public void test0_Axiom() throws Exception {
        Scanner sc = testInputs.get(0);
        String[] result = ms.solve(sc);
        Assert.assert(1,result);
    }
    @Test
    public void test1_Add() throws Exception {
        Scanner sc = testInputs.get(1);
        String[] result = ms.solve(sc);
        Assert.assertEquals(1,result);
    }
    @Test
    public void test2_Far() throws Exception {
        Scanner sc = testInputs.get(2);
        String[] result = ms.solve(sc);
        Assert.assertEquals(2,result);
    }
    @Test
    public void test3_Odd() throws Exception {
        Scanner sc = testInputs.get(3);
        String[] result = ms.solve(sc);
        Assert.assertEquals(5,result);
    }
    @Test
    public void test4_Powless() throws Exception {
        Scanner sc = testInputs.get(4);
        String[] result = ms.solve(sc);
        Assert.assertEquals(4,result);
    }
    @Test
    public void test5_Complex() throws Exception {
        Scanner sc = testInputs.get(5);
        String[] result = ms.solve(sc);
        Assert.assertEquals(2,result);
    }
    @Test
    public void test6_Last() throws Exception {
        Scanner sc = testInputs.get(6);
        String[] result = ms.solve(sc);
        Assert.assertEquals(12,result);
    }

}

