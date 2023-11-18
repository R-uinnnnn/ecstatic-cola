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
    cout << s3.c_str() << endl;
    cout << s4.c_str() << endl;
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

    //abl::string s2("world");
    ////cout << s2.capacity() << endl;
    //s2.push_back('c');
    //s2.push_back('c');
    //s2.push_back('c');
    //cout << s2 << endl;
    //s2 += 's';
    //cout << s2 << endl;
    //s2 += "good";
    //cout << s2 << endl;
    abl::string s3("hello");
    s3.append(" judy");
    cout << s3 << endl;
    //abl::string s4("helloooo");
    ////s4 += '\0';
    //cout << s4 << endl;
    //s4 += "wwwwwww";
    //s4.insert(2, 3, 'y');
    //cout << s4 << endl;
    //abl::string s5("hello");
    //s5.insert(2, 5, 'p');
    //cout << s5 << endl;
    //s5.insert(9, "world", 6);
    //cout << s5 << endl;
    //for (auto ch : s5)
    //{
    //    cout << ch;
    //}
    //cout << endl;

    //string s6;
    //cin >> s6;
    //cout << s6 << endl;
    //cin >> s6;
    //cout << s6;
   /* cout << s4.npos << endl;*/
}
void test_string3()
{
    abl::string s1("hello");
    abl::string s2("helloxxxxx");
    //cout << (s2 < s1) << endl;
    abl::string s3("hello");
    //cout << (s1 == s2) << endl;
    //cout << (s1 == s3) << endl;
    cout << (s2 >= s3) << endl;
    cout << (s1 >= s2) << endl;
    cout << (s1 >= s3) << endl;
}
void test_string4()
{
    abl::string s1("helloxxxxxxxxxxx");
    //abl::string s2;
    //s2 = s1;
    //cout << s1 << endl;
    //cout << s2 << endl;
    //s1.append(" world");
    abl::string s2("worldxxx");
    s1 = s2;
    cout << s1 << endl;
    cout << s2 << endl;
}
//int main()
//{
//    //test_string4();
//    string s("hello world");
//    string::iterator it = s.begin();
//    while (it != s.end())
//    {
//        *it = 'x';
//        it++;
//    }
//    cout << s << endl;
//    return 0;
//}
//int main()
//{
//    abl::string s1="heldljoasc";
//    cout << s1 << endl;
//    return 0;
//}
