#include <iostream>
#include <cstring>
using namespace std;
#include "String.h"

int main()
{

    std::string str1("jkdsajd");
    std::string str2;
    cout << str1.c_str() << endl;
    cout << str2.c_str() << endl;

    abl::string str3("hello world");
    abl::string::iterator it = str3.begin();

    while (it != str3.end())
    {
        cout << *it;
        it++;
    }
    cout << str3.c_str() << endl;
    str3.insert(5, 5, '%');
    cout << str3.c_str() << endl;
    cout << str3[0] << endl;
    getchar();
    return 0;
}