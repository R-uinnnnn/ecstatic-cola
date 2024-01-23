#include <iostream>
#include <list>
using namespace std;
#include "List.h"

void test2()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(21);
    lt.push_back(13);
    lt.push_back(14);
    lt.push_back(19);
    list<int>:: iterator it=lt.begin();
    for(int i=0;i<lt.size();i++)
    {
        cout<<*it<<endl;
        ++it;
    }

}
int main()
{
    /*
    list<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    lt1.push_back(5);
    lt1.push_back(6);
    list<int>::iterator it=lt1.begin();
    while(it!=lt1.end())
    //由于链表在内存中并不是连续存储的，因此++与解引用*不能正常使用；因此需要另外设计一个类，来对iterator进行++与解引用*的重载
    {
        cout<<*it<<endl;
        ++it;
    }
    */
    //annn::test1();
    test2();
    getchar();
    return 0;
}