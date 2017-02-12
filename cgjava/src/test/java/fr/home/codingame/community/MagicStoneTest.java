package fr.home.codingame.community;

import fr.home.codingame.TestInitializer;
import junit.framework.TestCase;
import org.junit.*;

import java.io.File;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * Created by lrhmf on 11/02/2017.
 */

public class MagicStoneTest {

    private static List<Scanner> testInputs;
    MagicStone ms = new MagicStone();

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
        int result = ms.solve(sc);
        Assert.assertEquals(1,result);
    }
    @Test
    public void test1_Add() throws Exception {
        Scanner sc = testInputs.get(1);
        int result = ms.solve(sc);
        Assert.assertEquals(1,result);
    }
    @Test
    public void test2_Far() throws Exception {
        Scanner sc = testInputs.get(2);
        int result = ms.solve(sc);
        Assert.assertEquals(2,result);
    }
    @Test
    public void test3_Odd() throws Exception {
        Scanner sc = testInputs.get(3);
        int result = ms.solve(sc);
        Assert.assertEquals(5,result);
    }
    @Test
    public void test4_Powless() throws Exception {
        Scanner sc = testInputs.get(4);
        int result = ms.solve(sc);
        Assert.assertEquals(4,result);
    }
    @Test
    public void test5_Complex() throws Exception {
        Scanner sc = testInputs.get(5);
        int result = ms.solve(sc);
        Assert.assertEquals(2,result);
    }
    @Test
    public void test6_Last() throws Exception {
        Scanner sc = testInputs.get(6);
        int result = ms.solve(sc);
        Assert.assertEquals(12,result);
    }






}