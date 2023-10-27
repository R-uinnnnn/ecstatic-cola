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
int main()
{
    string s1 = "+2147483647";
    int n = StrToInt(s1);
    cout << n << endl;
    return 0;
}