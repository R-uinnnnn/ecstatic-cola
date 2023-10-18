#include <iostream>
#include <cstring>
using namespace std;
#include "string.h"

int main()
{
    std::string str1("jkdsajd");
    std::string str2;
    cout<<str1.c_str()<<endl;
    cout<<str2.c_str()<<endl;
    STR::string str3("hello world");
    STR::string::iterator it=str3.begin();
    
    while(it!=str3.end())
    {
        cout<<*it;
        it++;
    }
    
    getchar();
    return 0;
}