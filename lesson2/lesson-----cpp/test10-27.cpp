#include <iostream>
#include <string>
#include <vector>
using namespace std;


int StrToInt(string str) {
    string::iterator it = str.begin();
    int flag = 0;
    if (*it == '+')
    {
        it++;
    }
    else if (*it == '-')
    {
        flag = 1;
        it++;
    }
    if (*it == '0')
    {
        return 0;
    }
    if (it == str.end())
    {
        return 0;
    }
    while (it != str.end())
    {
        if (*it < '0' || *it>'0' + 9)
        {
            return 0;
        }
        it++;
    }

    int num = 0;
    int i = 0;
    if (str[i] == '+' || str[i] == '-')
    {
        i++;
    }
    while (i != str.size())
    {
        num = num * 10 + (str[i] - '0');
        i++;
    }

    if (flag == 1)
    {
        num = -num;
    }
    else
    {
        str.erase(str.begin());
    }
    return num;

}
string addStrings(string num1, string num2)
{
    size_t i1 = num1.size() - 1;
    size_t i2 = num2.size() - 1;
    size_t carry = 0;//进位
    string num ;
    int ch = 0;
    int n1 = 0, n2 = 0;
    while (i1 != num1.npos || i2 != num2.npos)
    {
        if (i1 != num1.npos)
        {
            n1 = num1[i1] - '0';
        }
        if(i2!=num2.npos)
            n2 = num2[i2] - '0';
        if (i1 == num1.npos)
        {
            n1 = 0;
        }
        else if (i2 == num2.npos)
        {
            n2 = 0;
        }
        ch = n1 + n2+carry;
        num += (ch % 10 + '0');
        if (carry == 1)
            carry = 0;
        if (ch / 10 == 1)
        {
            carry = 1;
        }

        if(i1!=num1.npos)
        i1--;
        if(i2!=num2.npos)
        i2--;
    }
    if (carry == 1)
    {
        num += '1';
    }
    string::iterator it1 = num.begin();
    string::iterator it2 = num.end();
    reverse(it1, it2);//传递迭代器区间前闭后开
    return num;
}
void reverseString(vector<char>& s) {
    vector<char>::iterator it1 = s.begin();
    vector<char>::iterator it2 = s.end();
    reverse(it1, it2);
    vector<char>::iterator it = s.begin();
    while (it != s.end())
    {
        cout << *it;
        if (it < s.end() - 1)
            cout << ",";
        ++it;
    }
}
//int main()
//{
//    //string s1 = "+2147483647";
//    ////int n = StrToInt(s1);
//    //cout << n << endl;
//    string s1 = "9";
//    string s2 = "99";
//    string s3 = addStrings(s1, s2);
//    cout << s3 << endl;
//    //vector<char> s;
//    //string s4 = "hellowwww";
//    //size_t pos = 0;
//    //pos = s4.find('a');
//    //cout << pos << endl;
//    //cout << s4.npos << endl;
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

//int main() {
//    string s;
//    getline(cin, s);
//    int i = 0;
//    size_t pos = 0;
//    size_t flag = 0;
//    size_t count = 0;
//    while (s[i] != '\0')
//    {
//        size_t prepos = pos;
//        //if (pos == 0)
//        //    pos = s.find(' ', i);
//        //else
//            pos = s.find(' ', i);
//        if (pos == s.npos)
//        {
//            string s1 = s.substr(prepos+1, s.size() - prepos);
//            size_t x = s.size() - count - prepos + 1;
//            cout << x << endl;
//            break;
//        }
//        else
//        {
//            ++count;
//        }
//        i = (pos + 1);
//    }
//    return 0;
//
//}

int main()
{
    string s1="hello string";
    size_t pos = 0;
    pos = s1.find(' ', 0);
    cout << pos << endl;
    pos = s1.find('a', pos + 1);
    cout << pos << endl;

    return 0;
}

int singleNumber(vector<int>& nums) {
    size_t i = 0;
    int x = 0;
    while (i < nums.size())
    {
        x ^= nums[i++];
    }
    return x;
}
//int main()
//{
//    int a[10] = { 0,1,2,3,4,5,6,7,8,9 };
//    vector<int> num(a, a + 9);
//
//    return 0;
//}