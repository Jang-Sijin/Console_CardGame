using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Library.JSJ.String
{   
    public class MyString
    {
        #region string Member 변수
        private string _string; // string 문자열
        public string String // 프로퍼티용 
        {
            get
            {
                return _string;
            }
            private set
            {
                _string = value;
            }
        }
        #endregion

        #region MyString 생성자
        public MyString()
        {

        }

        // Constructor: Insert string parameter
        public MyString(string value)
        {
            _string = value;
        }

        // .Reverse().ToArray() > char[] 반환을 위한 생성자      
        //public MyString(char[] value)
        //{
        //    foreach (char ch in value)
        //    {
        //        _string += ch;
        //    }
        //}
        #endregion

        #region MyString 이동생성자
        // string을 MyString으로 암시적으로 변환하는 연산자
        public static implicit operator MyString(string value)
        {
            return new MyString(value);
        }

        // MyString을 string으로 암시적으로 변환하는 연산자
        public static implicit operator string(MyString myString)
        {
            return myString._string;
        }

        public static implicit operator MyString(char[] char_get)
        {
            string temp = "";

            foreach (char ch in char_get)
            {
                temp += ch;
            }

            return new MyString(temp);
        }
        #endregion

        #region CompareTo Methods
        public virtual int CompareTo(MyString str)
        {
            if (_string == str)
                return 0;

            if (_string == null)
                return -1;

            if (str == null)
                return 1;

            int lengthA = _string.Length;
            int lengthB = str._string.Length;
            int minLength = lengthA < lengthB ? lengthA : lengthB;

            for (int i = 0; i < minLength; i++)
            {
                if (_string[i] != str._string[i])
                    return _string[i] - str._string[i] < 0 ? -1 : 1;
            }

            return lengthA - lengthB < 0 ? -1 : 1;
        }
        #endregion

        #region Equals Methods
        public virtual bool Equals(string value)
        {
            if (_string == value)
                return true;
            else
                return false;
        }

        public virtual bool Equals(MyString value)
        {
            if (_string == value)                
                return true;
            else
                return false;
        }
        #endregion

        // 구현중
        #region Split Methods
        //public string[] Split(char[] splitStandard)
        //{
        //    // 동일한 단어가 있는지 검색하고 
        //    List<string> result = new List<string>();
        //    string resultString;
        //
        //    for(int index = 0; index < _string.Length; index++)
        //    {
        //        if(_string[index] == splitStandard[0])
        //        {
        //            for(int i = 0; i < splitStandard.Length; i++)
        //            {
        //                if (_string[index + i] != splitStandard[i])                           
        //                    break;
        //
        //                if(i == splitStandard.Length - 1)
        //                {
        //                    for(int resultIndex = index; resultIndex < )
        //                }
        //            }
        //        }
        //    }
        //
        //    // return ;
        //}
        #endregion

        // 구현중
        #region Replace Methods
        public virtual string Split(char a, char b)
        {
            return "";
        }

        public virtual string Split(string a, string b)
        {
            return "";
        }

        #endregion        

        #region Reverse Methods
        public virtual IEnumerable<char> Reverse()
        {
            if (_string == null)
                throw new ArgumentNullException();

            for (int index = _string.Length - 1; 0 <= index; index--)
            {
                yield return _string[index];
            }
        }
        #endregion                
    }
}

#region 구현 메서드
// CompareTo
// Equals
// Split
// Respace
// Reverse
#endregion