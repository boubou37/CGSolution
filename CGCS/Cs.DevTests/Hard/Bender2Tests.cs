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
    public class Bender2Tests : CGTests
    {
        Bender2 bend = new Bender2("Hard", "Bender2");
        static StreamReader[] sr;
        static int testNum = 9;

        [ClassInitialize()]
        public static void initFiles(TestContext context)
        {
            sr = new StreamReader[testNum];
            for (int i = 0; i < testNum; i++)
            {
                sr[i] = new StreamReader(fold + "Hard\\Bender2\\Test" + i + ".txt");
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
        public void TestBender2_0_OneRoom()
        {
            int result = bend.MaxMoney(sr[0]);
            Assert.AreEqual(200, result);
        }

        [TestMethod()]
        public void TestBender2_1_ThreeRoom()
        {
            int result = bend.MaxMoney(sr[1]);
            Assert.AreEqual(40, result);
        }


        [TestMethod()]
        public void TestBender2_2_15rooms()
        {
            int result = bend.MaxMoney(sr[2]);
            Assert.AreEqual(88, result);
        }



        [TestMethod()]
        public void TestBender2_3()
        {
            int result = bend.MaxMoney(sr[3]);
            Assert.AreEqual(358, result);
        }


        [TestMethod()]
        public void TestBender2_4()
        {
            int result = bend.MaxMoney(sr[4]);
            Assert.AreEqual(1928, result);
        }


        [TestMethod()]
        public void TestBender2_5()
        {
            int result = bend.MaxMoney(sr[5]);
            Assert.AreEqual(75413, result);
        }

        [TestMethod()]
        public void TestBender2_6()
        {
            int result = bend.MaxMoney(sr[6]);
            Assert.AreEqual(103558, result);
        }


        [TestMethod()]
        public void TestBender2_7_SquareBuilding()
        {
            int result = bend.MaxMoney(sr[7]);
            Assert.AreEqual(400, result);
        }


        [TestMethod()]
        public void TestBender2_8_MultipleEntries()
        {
            int result = bend.MaxMoney(sr[8]);
            Assert.AreEqual(358, result);
        }
    }
}