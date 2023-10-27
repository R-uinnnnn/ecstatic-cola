#include <iostream>
#include <string>
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
    size_t carry = 0;//��λ
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
        ch = n1 + n2;
        num += (ch % 10 + carry + '0');
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
    reverse(it1, it2);//���ݵ���������ǰ�պ�
    return num;
}
int main()
{ 
    //string s1 = "+2147483647";
    ////int n = StrToInt(s1);
    //cout << n << endl;
    string s1 = "1234";
    string s2 = "236";
    string s3 = addStrings(s1, s2);
    cout << s3 << endl;
    return 0;
}