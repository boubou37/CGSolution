using System;
using Microsoft.VisualStudio.TestTools.UnitTesting;
using Cs.Dev.Easy;
using System.IO;

namespace Cs.DevTests.Easy
{
    [TestClass]
    public class TemperaturesTest : CGTests
    {
        Temperatures t = new Temperatures("Easy","Temperatures");
        StreamReader sr;

        [TestCleanup()]
        public void closeStream()
        {
            sr.Dispose();
        }

        [TestMethod]
        public void TestLowerTemp0()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test0.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(1, obtained);
        }

        [TestMethod]
        public void TestLowerTemp1()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test1.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(-5, obtained);
        }

        [TestMethod]
        public void TestLowerTemp2()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test2.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(5, obtained);
        }

        [TestMethod]
        public void TestLowerTemp3()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test3.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(5, obtained);
        }

        [TestMethod]
        public void TestLowerTemp4()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test4.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(2, obtained);
        }


        [TestMethod]
        public void TestLowerTemp5()
        {
            sr = new StreamReader(fold + t.PuzCategory + "\\" + t.PuzName + "\\Test5.txt");
            int obtained = t.getMinTemp(sr);
            Assert.AreEqual(0, obtained);
        }
    }
}
