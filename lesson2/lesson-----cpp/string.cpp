#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

void test_string1()
{
    abl::string s1("hello world");
    abl::string s2("legacy.cplusplus.com");
    string s3("jdksanxkdsd");
    string s4;
    //cout << s3.c_str() << endl;
    //cout << s4.c_str() << endl;
    cout << s1.c_str() << endl;
    for (size_t i = 0; i < s1.size(); i++)
    {
        cout << s1[i] << " ";
    }
    cout << endl;
    cout << s2.c_str() << endl;
    abl::string::iterator it = s2.begin();
    while(it!=s2.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;
    cout << s2 << endl;
}
void test_string2()
{
    //string s1("hello");
    //cout << s1 << endl;
    //cout << s1.capacity() << endl;

    abl::string s2("world");
    //cout << s2.capacity() << endl;
    s2.push_back('c');
    s2.push_back('c');
    s2.push_back('c');
    cout << s2 << endl;
    s2 += 's';
    cout << s2 << endl;
    s2 += "good";
    cout << s2 << endl;
    abl::string s3("hello");
    s3.append(" judy");
    cout << s3 << endl;
    string s4("helloooo");
    s4 += '\0';
    cout << s4 << endl;
    s4 += "wwwwwww";
    cout << s4 << endl;
}
int main()
{
    test_string2();
    return 0;
}