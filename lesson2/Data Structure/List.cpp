#include <iostream>
#include <list>
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
    //�����������ڴ��в����������洢�ģ����++�������*��������ʹ�ã������Ҫ�������һ���࣬����iterator����++�������*������
    {
        cout<<*it<<endl;
        ++it;
    }
    */
    test1();

    return 0;
}