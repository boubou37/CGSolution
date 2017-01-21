using Microsoft.VisualStudio.TestTools.UnitTesting;
using Cs.Dev.Hard;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Cs.DevTests
{
    [TestClass()]
    public class Bender3Tests : CGTests
    {

        Bender3 bend = new Bender3("Hard", "Bender3");
        static StreamReader[] sr;
        static int testNum = 8;

        [ClassInitialize()]
        public static void initFiles(TestContext context)
        {
            sr = new StreamReader[testNum];
            for (int i = 0; i < testNum; i++)
            {
                sr[i] = new StreamReader(fold + "Hard\\Bender3\\Test" + i + ".txt");
            }
        }

        [ClassCleanup()]
        public static void cleanStreams()
        {
            foreach (StreamReader s in sr)
            {
                s.Dispose();
            }
        }

        [TestMethod()]
        public void TestBender3_0_O1()
        {
            string result = bend.FindComplexity(sr[0]);
            Assert.AreEqual("O(1)", result);
        }

        [TestMethod()]
        public void TestBender3_1_Ologn()
        {
            string result = bend.FindComplexity(sr[1]);
            Assert.AreEqual("O(log n)", result);
        }


        [TestMethod()]
        public void TestBender3_2_On()
        {
            string result = bend.FindComplexity(sr[2]);
            Assert.AreEqual("O(n)", result);
        }



        [TestMethod()]
        public void TestBender3_3_Onlogn()
        {
            string result = bend.FindComplexity(sr[3]);
            Assert.AreEqual("O(n log n)", result);
        }


        [TestMethod()]
        public void TestBender3_On2()
        {
            string result = bend.FindComplexity(sr[4]);
            Assert.AreEqual("O(n^2)", result);
        }


        [TestMethod()]
        public void TestBender3_On2logn()
        {
            string result = bend.FindComplexity(sr[5]);
            Assert.AreEqual("O(n^2 log n)", result);
        }

        [TestMethod()]
        public void TestBender3_On3()
        {
            string result = bend.FindComplexity(sr[6]);
            Assert.AreEqual("O(n^3)", result);
        }


        [TestMethod()]
        public void TestBender3_7_O2pown()
        {
            string result = bend.FindComplexity(sr[7]);
            Assert.AreEqual("O(2^n)", result);
        }


    }
}