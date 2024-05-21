using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Library.JSJ.String
{
    public class MyString
    {
        #region Member Variable(멤버 변수)
        private char[] _mutableChar; // 캐릭터 가변 배열 (생성자에서 할당 필요) // 참조 타입(Reference Type)
        private int _length; // 캐릭터 가변 배열의 길이 설정
        public int Length // getter >> 배열 길이를 반환한다.
        {
            get => _length;
        }

        public int Capacity // getter >> 가변 캐릭터 길이의 용량을 반환한다.
        {
            get => _mutableChar.Length;
        }
        #endregion

        #region MyString Char Array Indexing
        // MyString 가변 배열에 인덱싱으로 접근 가능하도록 구현.
        // getter: MyString[index]로 접근 시, 해당 index char value를 반환한다.
        // setter: MyString[index]로 접근 후, char 할당 시 해당 index에 value를 넣어준다.
        public char this[int index]
        {
            get
            {
                if (0 > index || _length <= index) // 가변 배열의 범위를 넘어감
                {
                    // 잘못된 인덱스가 배열 또는 컬렉션의 멤버에 액세스하거나 버퍼의 특정 위치에서 읽거나 쓰는 데 사용되는 경우 예외가 throw 반환
                    // Out of Range
                    throw new IndexOutOfRangeException("MyString Index Out of Range: _mutableChar");
                }

                return _mutableChar[index];
            }
            set
            {
                if (0 > index || _length <= index)
                {
                    throw new IndexOutOfRangeException("MyString Index Out of Range: _mutableChar");
                }

                _mutableChar[index] = value;
            }
        }
        #endregion

        #region MyString 생성자
        // 1. Constructor: Insert string parameter
        public MyString(string str)
        {
            _mutableChar = new char[str.Length];
            _length = str.Length;

            Copy(str, str.Length, this); // string을 MyString class에 복사한다.
        }

        // 2. Constructor: .Reverse().ToArray() > char[] 반환을 위한 생성자
        public MyString(char[] input_char)
        {
            _mutableChar = new char[input_char.Length];

            Copy(input_char, input_char.Length, _mutableChar);
        }

        // MyString myString += char ch; 가능하도록 +연산자 추가.
        public static MyString operator +(MyString myString, char ch)
        {
            if (myString == null)
                throw new ArgumentException("myString is null");

            if(myString._length == myString.Capacity)
            {
                myString.ReallocationCapacity(myString._length + 1); // 동적 배열 크기 1byte 추가해서 재할당.
            }
            myString += ch; // Add char Parameter

            return myString;
        }

        public static MyString operator +(MyString myString, MyString addMyString)
        {
            if (myString == null)
                throw new ArgumentException("myString is null");

            if (myString._length == myString.Capacity)
            {
                myString.ReallocationCapacity(myString._length + addMyString._length);
            }
            myString += addMyString;

            return myString;
        }
        #endregion

        #region MyString 암시적 형변환(Type Conversion)
        // 1. string to MyString
        // string을 MyString으로 암시적으로 변환하는 연산자
        // 암시적(implicit): 명확하게 표현되지 않더라도 자동으로 수행되는 것을 의미한다.
        // ex) MyString myString = $"문자열"; << string으로 변환
        public static implicit operator MyString(string value)
        {
            return new MyString(value);
        }

        // 2. char[] to MyString
        // 캐릭터 배열을 MyString으로 암시적으로 변환하는 연산자
        // 암시적 형변환은 바로 위에 구현함. (public static implicit operator MyString(string value))
        public static implicit operator MyString(char[] char_get)
        {
            return new string(char_get);
        }

        // 3. MyString을 string으로 암시적으로 변환하는 연산자
        // ex) string str;
        //     MyString myString = new MyString("Test String");
        //     str = myString;
        public static implicit operator string(MyString myString)
        {            
            return new string(myString._mutableChar);
        }
        #endregion

        #region MyString Function 기능 추가한 것
        public MyString Copy(string sourceString, int sourceIndex, MyString destinationMyString) // destination: 목적지
        {
            for (int i = 0; i < sourceIndex; i++)
            {
                destinationMyString[i] = sourceString[i];
            }

            return destinationMyString;
        }

        public MyString Copy(char[] sourceCharArray, int sourceIndex, MyString destinationMyString) // destination: 목적지
        {
            for (int i = 0; i < sourceIndex; i++)
            {
                destinationMyString[i] = sourceCharArray[i];
            }

            return destinationMyString;
        }

        // Substring 메소드 구현
        public MyString Substring(int startIndex, int length)
        {
            if (startIndex < 0 || length < 0 || startIndex + length > Length)
            {
                throw new ArgumentOutOfRangeException();
            }

            char[] substringChars = new char[length];
            Array.Copy(_mutableChar, startIndex, substringChars, 0, length);
            return new MyString(new string(substringChars));
        }

        public MyString Substring(int startIndex)
        {
            if (startIndex < 0 || startIndex >= Length)
            {
                throw new ArgumentOutOfRangeException();
            }

            int length = Length - startIndex;
            return Substring(startIndex, length);
        }

        public void ReallocationCapacity(int newMyStringLength)
        {
            if(this.Capacity < newMyStringLength)
            {
                int newCapacity = Capacity == 0 ? newMyStringLength : (int)(1.5 * Capacity);

                char[] newCharArray = new char[newCapacity];
                Array.Copy(_mutableChar, newCharArray, _length);                
            }
        }
        #endregion

        // ============================================= //

        #region CompareTo Methods
        // CompareTo 메소드는 주로 정렬 또는 사전순 작업에 사용하도록 설계되었다고 한다. (MSDN)
        // 메서드 호출의 주요 목적이 두 문자열이 동일한지 여부를 확인하는 경우 사용하지 않아야한다.
        // 두 문자열이 동일한지 여부를 확인하려면 Equals 메서드를 호출하는 것이 일반적이다.
        // 내 MyString 가변 배열에 존재하는 문자열과 동일한 문자열을 가지고 있을 때, 0을 반환한다.
        // 비교 string 값이 동일하지 않다면 사전 순으로 비교하여, -1 또는 1 값을 반환한다.
        // return -1: 나의 인스턴스가 parameter로 받은 문자열보다 사전 순으로 앞에 위치할 때 반환되는 값이다.
        // return 1: 나의 인스턴스가 patameter로 받은 문자열보다 사전 순으로 뒤에 위치할 때 반환되는 값이다.
        public virtual int CompareTo(string str)
        {
            if (new string(_mutableChar) == str)
                return 0;

            if (_mutableChar == null)
                return -1;

            if (str == null)
                return 1;

            int lengthA = _mutableChar.Length;
            int lengthB = str.Length;
            int minLength = lengthA < lengthB ? lengthA : lengthB;

            for (int i = 0; i < minLength; i++)
            {
                if (_mutableChar[i] != str[i])
                    return _mutableChar[i] - str[i] < 0 ? -1 : 1;
            }

            return lengthA - lengthB < 0 ? -1 : 1;
        }

        public virtual int CompareTo(MyString myString)
        {
            int lengthA = _mutableChar.Length;
            int lengthB = myString._mutableChar.Length;
            int minLength = lengthA < lengthB ? lengthA : lengthB;

            for (int i = 0; i < minLength; i++)
            {
                if (_mutableChar[i] != myString._mutableChar[i])
                    return _mutableChar[i] - myString._mutableChar[i] < 0 ? -1 : 1;
            }

            if (lengthA < lengthB)
                return 1;
            else if (lengthA > lengthB)
                return -1;
            else
                return 0;
        }

        public virtual int CompareTo(object obj)
        {
            MyString myString = obj as MyString; // object 타입이라고 하더라도 MyString 클래스만 받을 수 있도록 처리한다. 사실상 예외 처리를 해주는 Function이다.

            if(myString != null)
            {
                return CompareTo(myString);
            }
            else
            {
                throw new ArgumentException("This Object is not a MyString Class Type.");
            }
        }
        #endregion

        #region Equals Methods
        public virtual bool Equals(string str)
        {
            if (str == null)
                return false;

            return new string(_mutableChar) == str;
        }

        public virtual bool Equals(MyString myString)
        {
            if (myString == null) 
                return false;
            
            if (_mutableChar.Length != myString._mutableChar.Length) 
                return false;

            for (int i = 0; i < _mutableChar.Length; i++)
            {
                if (_mutableChar[i] != myString._mutableChar[i])
                {
                    return false;
                }
            }

            return true;
        }
        #endregion

        #region Split Methods
        // 스플릿 알고리즘
        // 1. lastSplitIndex >> 마지막으로 스플릿을 끝낸 인덱스
        // 2. 순회하면서 현재 i부터 시작해서 i + separator.Length - 1만큼 문자를 비교를 한다.
        // 3. 만약에 [i,i+separator.Length-1]의 문자열이 separator 문자열과 동일한 경우
        // 4. [lastSplitIndex, i-1]만큼의 문자열을 잘라서 결과값에 저장한다.
        // 5. 1~4의 과정을 수행한 경우 남은 부분인 [lastSplitIndex, Length - 1]을 결과 List<MyString>에 넣고 리턴한다.
        public MyString[] Split(MyString separator)
        {
            List<MyString> result = new List<MyString>();
            int lastSplitIndex = 0;
            int separatorLength = separator.Length;

            for (int i = 0; i < Length - (separatorLength - 1); i++)
            {
                bool isMatch = true;
                for (int j = 0; j < separatorLength; j++)
                {
                    if (_mutableChar[i + j] != separator[j])
                    {
                        isMatch = false;
                        break;
                    }
                }

                if (isMatch)
                {
                    MyString splitSegment = Substring(lastSplitIndex, i - lastSplitIndex);
                    result.Add(splitSegment);
                    lastSplitIndex = i + separatorLength;
                    i = lastSplitIndex - 1; // Move the index forward
                }
            }

            // Add the remaining part
            if (lastSplitIndex < Length)
            {
                MyString lastSegment = Substring(lastSplitIndex);
                result.Add(lastSegment);
            }

            return result.ToArray();
        }
        #endregion

        #region Replace Methods
        public MyString Replace(MyString oldMyString, MyString newMyString)
        {
            List<MyString> result = new List<MyString>();
            int lastSplitIndex = 0;
            int separatorLength = oldMyString.Length;

            for (int i = 0; i < Length - (separatorLength - 1); i++)
            {
                bool isMatch = true;
                for (int j = 0; j < separatorLength; j++)
                {
                    if (_mutableChar[i + j] != oldMyString[j])
                    {
                        isMatch = false;
                        break;
                    }
                }

                if (isMatch)
                {
                    MyString splitSegment = Substring(lastSplitIndex, i - lastSplitIndex);
                    result.Add(splitSegment);
                    result.Add(newMyString); // *Add newMyString 
                    lastSplitIndex = i + separatorLength;
                    i = lastSplitIndex - 1; // Move the index forward
                }
            }

            // Add the remaining part
            if (lastSplitIndex < Length)
            {
                MyString lastSegment = Substring(lastSplitIndex);
                result.Add(lastSegment);
            }

            return result.ToArray().ToString();
        }
        #endregion

        #region Reverse Methods
        public virtual char[] Reverse()
        {
            if (_mutableChar == null)
                throw new ArgumentNullException();

            char[] reverseCharArray = new char[_mutableChar.Length];            
            for (int index = _mutableChar.Length - 1; 0 <= index; index--)
            {                
                reverseCharArray[_mutableChar.Length - 1 - index] += _mutableChar[index];
            }
            return reverseCharArray;
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