#include <iostream>
#include <cstring>
using namespace std;
#include "string2.h"
void test_string1()
{
    abl::string s1("hello world");
    cout<<s1.c_str()<<endl;
    for(int i=0;i<=s1.size();i++)
    {
        cout<<s1[i]<<" ";
    }
}
int main()
{
    test_string1();
    getchar();
    return 0;
}