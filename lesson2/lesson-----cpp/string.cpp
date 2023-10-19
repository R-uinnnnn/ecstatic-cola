#include <iostream>
#include <cstring>
using namespace std;
#include "String.h"
void test_string1()
{
    abl::string s1("hello world");
    cout << s1.c_str() << endl;
}
int main()
{
    test_string1();
    return 0;
}