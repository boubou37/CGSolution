using Microsoft.VisualStudio.TestTools.UnitTesting;
using Cs.Dev.Normal;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Cs.DevTests
{
    [TestClass()]
    public class ScrabbleTests : CGTests
    {

        Scrabble sc = new Scrabble("Normal", "Scrabble");
        static StreamReader[] sr;
        static int testNum = 8;

        [ClassInitialize()]
        public static void initFiles(TestContext context)
        {
            sr = new StreamReader[testNum];
            for (int i = 0; i < testNum; i++)
            {
                sr[i] = new StreamReader(fold + "Normal\\Scrabble\\Test" + i + ".txt");
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
        public void TestScrabble0()
        {
            string result = sc.BestWord(sr[0]);
            Assert.AreEqual("which", result.Trim());
        }

        [TestMethod()]
        public void TestScrabble1()
        {
            string result = sc.BestWord(sr[1]);
            Assert.AreEqual("potsie", result.Trim());
        }


        [TestMethod()]
        public void TestScrabble2()
        {
            string result = sc.BestWord(sr[2]);
            Assert.AreEqual("powers", result.Trim());
        }



        [TestMethod()]
        public void TestScrabble3()
        {
            string result = sc.BestWord(sr[3]);
            Assert.AreEqual("waster", result.Trim());
        }


        [TestMethod()]
        public void TestScrabble4()
        {
            string result = sc.BestWord(sr[4]);
            Assert.AreEqual("tween", result.Trim());
        }


        [TestMethod()]
        public void TestScrabble5()
        {
            string result = sc.BestWord(sr[5]);
            Assert.AreEqual("aeiou", result.Trim());
        }

        [TestMethod()]
        public void TestScrabble6()
        {
            string result = sc.BestWord(sr[6]);
            Assert.AreEqual("satire", result.Trim());
        }


        [TestMethod()]
        public void TestScrabble7()
        {
            string result = sc.BestWord(sr[7]);
            Assert.AreEqual("pastern", result.Trim());
        }

    }
}