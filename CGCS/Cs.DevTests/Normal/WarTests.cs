using Microsoft.VisualStudio.TestTools.UnitTesting;
using Cs.Dev.Normal;
using System.IO;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.DevTests
{
    [TestClass()]
    public class WarTests : CGTests
    {
        War wr = new War("Normal", "War");
        static int testNum = 9;
        static StreamReader[] sr;

        [ClassInitialize()]
        public static void initFiles(TestContext context)
        {
            sr = new StreamReader[testNum];
            for (int i=0; i< testNum; i++)
            {
                sr[i] = new StreamReader(fold + "Normal\\War\\Test"+i+".txt");
            }
        }

        [ClassCleanup()]
        public static void cleanStreams()
        {
            foreach(StreamReader s in sr)
            {
                s.Dispose();
            }
        }

        [TestMethod()]
        public void Simple()
        {
            string result = wr.GetWinner(sr[0]);
            Assert.AreEqual("1 3", result.Trim());
        }


        [TestMethod()]
        public void Alternated()
        {
            string result = wr.GetWinner(sr[1]);
            Assert.AreEqual("2 26", result.Trim());
        }

        [TestMethod()]
        public void Longer()
        {
            string result = wr.GetWinner(sr[2]);
            Assert.AreEqual("2 56", result.Trim());
        }


        [TestMethod()]
        public void Battle()
        {
            string result = wr.GetWinner(sr[3]);
            Assert.AreEqual("2 1", result.Trim());
        }



        [TestMethod()]
        public void AnotherBattle()
        {
            string result = wr.GetWinner(sr[4]);
            Assert.AreEqual("1 52", result.Trim());
        }


        [TestMethod()]
        public void ChainedBattles()
        {
            string result = wr.GetWinner(sr[5]);
            Assert.AreEqual("2 1", result.Trim());
        }

        [TestMethod()]
        public void LongOne()
        {
            string result = wr.GetWinner(sr[6]);
            Assert.AreEqual("2 1262", result.Trim());
        }


        [TestMethod()]
        public void PAT()
        {
            string result = wr.GetWinner(sr[7]);
            Assert.AreEqual("PAT", result.Trim());
        }


        [TestMethod()]
        public void PATBis()
        {
            string result = wr.GetWinner(sr[8]);
            Assert.AreEqual("PAT", result.Trim());
        }

    }
}