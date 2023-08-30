#include <iostream>
namespace A
{
    int a=100000000;
}

//using namespace A;//展开命名空间
using A::a; n 
int main() 
{
    int a=20;
    std::cout<< A::a << ": " << a << std::endl;
    getchar();
    return 0;
}