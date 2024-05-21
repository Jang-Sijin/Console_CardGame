using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Library.JSJ.String;

namespace _240517_장시진_숙제_String
{
    class Program
    {
        static void Main(string[] args)
        {                       
            #region string CompareTo
            Console.WriteLine("==============================================");
            Console.WriteLine("#Step 1. string CompareTo VS myString CompareTo");

            // #1. string CompareTo -> return -1
            string[] name = { "육개장", "윰개장" };
            int result = name[0].CompareTo(name[1]);
            Console.WriteLine(result);

            // #2. string CompareTo -> return 0
            name[1] = "육개장";
            result = name[0].CompareTo(name[1]);
            Console.WriteLine(result);

            // #3. string CompareTo -> return 1
            name[1] = "육가장";
            result = name[0].CompareTo(name[1]);
            Console.WriteLine(result);


            Console.WriteLine();
            

            // #1. MyStirng CompareTo -> return -1
            MyString myName0 = new MyString("육개장");
            // myName0 = "육개장";             // > public static implicit operator MyString(string value)
            // string changeString = myName0; // > public static implicit operator string(MyString myString)
            MyString myName1 = "윰개장";          
            int myResult = myName0.CompareTo(myName1);
            Console.WriteLine(myResult);

            // #2. MyStirng CompareTo -> return 0
            myName1 = "육개장";
            myResult = myName0.CompareTo(myName1);
            Console.WriteLine(myResult);

            // #3. MyStirng CompareTo -> return 1
            myName1 = "육가장";
            myResult = myName0.CompareTo(myName1);
            Console.WriteLine(myResult);            
            #endregion
            
            #region string Equals
            Console.WriteLine("==============================================");
            Console.WriteLine("#Step 2. string Equals VS myString Equals");

            // #1. string Equals -> return false
            string[] stringEquals = { "육개장", "윰개장" };
            bool resultEquals = stringEquals[0].Equals(stringEquals[1]);
            Console.WriteLine(resultEquals);

            // #2. string Equals -> return true
            stringEquals[1] = "육개장";
            resultEquals = stringEquals[0].Equals(stringEquals[1]);
            Console.WriteLine(resultEquals);


            Console.WriteLine();


            // #1. string Equals -> return false
            MyString[] myStringEquals = { "육개장", "윰개장" };
            resultEquals = myStringEquals[0].Equals(myStringEquals[1]);
            Console.WriteLine(resultEquals);

            // #2. string Equals -> return true
            myStringEquals[1] = "육개장";
            resultEquals = myStringEquals[0].Equals(myStringEquals[1]);
            Console.WriteLine(resultEquals);
            #endregion

            // 구현중
            #region string Split            
            Console.WriteLine("==============================================");
            Console.WriteLine("#Step 3. string Split VS myString Split");

            // #1. string Split -> return ' ' 단위로 문자열 반환
            string stringSplit = "나는 육개장을 좋아합니다.";
            Console.WriteLine(stringSplit);            
            string[] stringSplits = stringSplit.Split(' ');
            foreach(string iter in stringSplits)            
                Console.WriteLine(iter);
            Console.WriteLine();

            // #2. MyString Split -> return ' ' 단위로 문자열 반환
            MyString myStringSplit = "나는 육개장을 좋아합니다.";
            Console.WriteLine(myStringSplit);
            MyString[] myStringSplits = myStringSplit.Split(" ");
            foreach (string iter in myStringSplits)
                Console.WriteLine(iter);
            Console.WriteLine();            
            #endregion

            // 구현중
            #region string Replace
            Console.WriteLine("==============================================");
            Console.WriteLine("#Step 4. string Replace VS myString Replace");
           
            // #1. string Split -> return ' ' 단위로 문자열 반환
            string stringReplace = "나는 육개장을 좋아합니다.";
            Console.WriteLine(stringReplace);
            string resultStringReplace = stringReplace.Replace(' ', '#');            
            Console.WriteLine(resultStringReplace);
            Console.WriteLine();

            // #2. MyString Split -> return ' ' 단위로 문자열 반환
            MyString myStringReplace = "나는 육개장을 좋아합니다.";
            Console.WriteLine(myStringReplace);
            MyString resultMyStringReplace = myStringReplace.Replace(" ", "#");
            Console.WriteLine(resultStringReplace);
            Console.WriteLine();
            #endregion

            #region string Reverse     
            Console.WriteLine("==============================================");
            Console.WriteLine("#Step 5. string Reverse VS myString Reverse");
            string stringReverse = "Hello, World!";
            string reversed = new string(stringReverse.Reverse().ToArray());
            Console.WriteLine(reversed);

            MyString myStringReverse = "Hello, World!";
            MyString myReverse = myStringReverse.Reverse();
            Console.WriteLine(myReverse);
            #endregion
        }
    }
}
