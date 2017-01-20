using Microsoft.VisualStudio.TestTools.UnitTesting;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cs.DevTests.Community
{
    [TestClass()]
    public class AnagramTests : CGTests
    {
        private StreamReader sr;
        Anagram a = new Anagram("Community", "Anagrams");

        [TestCleanup()]
        public void closeStream()
        {
            sr.Dispose();
        }

        [TestMethod()]
        public void DecypherTest0()
        {
            sr = new StreamReader(fold + a.PuzCategory + "\\" + a.PuzName + "\\Test0.txt");
            string input = sr.ReadLine().Trim();
            Assert.AreEqual(a.Decypher(input), "END OF LINE");
        }


        [TestMethod()]
        public void DecypherTest1()
        {
            sr = new StreamReader(fold + a.PuzCategory + "\\" + a.PuzName + "\\Test1.txt");
            string input = sr.ReadLine().Trim();
            Assert.AreEqual(a.Decypher(input), "I KNOW KUNG FU");
        }


        [TestMethod()]
        public void DecypherTest2()
        {
            sr = new StreamReader(fold + a.PuzCategory + "\\" + a.PuzName + "\\Test2.txt");
            string input = sr.ReadLine().Trim();
            Assert.AreEqual(a.Decypher(input), "IM SORRY DAVE IM AFRAID I CANT DO THAT");
        }



        [TestMethod()]
        public void DecypherTest3()
        {
            sr = new StreamReader(fold + a.PuzCategory + "\\" + a.PuzName + "\\Test3.txt");
            string input = sr.ReadLine().Trim();
            Assert.AreEqual(a.Decypher(input), "TWAS BRILLIG AND THE SLITHY TOVES DID GYRE AND GIMBLE IN THE WABE ALL MIMSY WERE THE BOROGOVES AND THE MOME RATHS OUTGRABE");
        }
    }
}