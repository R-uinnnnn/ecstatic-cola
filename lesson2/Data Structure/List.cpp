#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
#include "List.h"

void test1()
{
    annn::List<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    lt1.push_back(5);
    lt1.push_back(6);
    lt1.push_back(7);

    annn::List<int>::iterator it = lt1.begin();
    //cout << *it << endl;
    //++it;
    //cout << *it << endl;
    //++it;
    //cout << *it << endl;
    //++lt1.begin();
    while (it != lt1.end())
    {
        cout << *it << " ";
        ++it;
    }

    //list<int> lt2;
    //lt2.push_back(13);
    //lt2.push_back(14);
    //lt2.push_back(10);
    //list<int>::iterator it2=lt2.begin();
    //++it2;

}
void test2()
{
    annn::List<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    annn::List<int> lt2;
    lt2.push_back(5);
    lt2.push_back(6);
    lt2.push_back(7);
    lt2.push_back(8);
    lt2.push_back(9);
    annn::List<int> lt3=lt1;
    lt2 = lt1;
    annn::List<int>::iterator it1 = lt1.begin();

    cout << "lt1:";
    while(it1!=lt1.end())
    {
        cout << *it1 << " ";
        ++it1;
    }
    cout << endl;
    annn::List<int>::iterator it2 = lt2.begin();
    while (it2 != lt2.end())
    {
        cout << *it2 << " ";
        ++it2;
    }

    annn::List<int>::iterator it3 = lt3.begin();
    while (it3 != lt3.end())
    {
        cout << *it3 << " ";
        ++it3;
    }
}
//int main()
//{
//    /*
//    list<int> lt1;
//    lt1.push_back(1);
//    lt1.push_back(2);
//    lt1.push_back(3);
//    lt1.push_back(4);
//    lt1.push_back(5);
//    lt1.push_back(6);
//    list<int>::iterator it=lt1.begin();
//    while(it!=lt1.end())
//    //由于链表在内存中并不是连续存储的，因此++与解引用*不能正常使用；因此需要另外设计一个类，来对iterator进行++与解引用*的重载
//    {
//        cout<<*it<<endl;
//        ++it;
//    }
//    */
//    test2();
//
//    return 0;
//}