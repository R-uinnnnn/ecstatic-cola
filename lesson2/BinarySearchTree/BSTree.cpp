#include <iostream>
#include <stdio.h>
using namespace std;
#include "BSTree.h"
void test1()
{
	BSTree<int> n1;
	n1.Insert(8);
	n1.Insert(3);
	n1.Insert(10);
	n1.Insert(1);
	n1.Insert(6);
	n1.Insert(4);
	n1.Insert(7);
	n1.Insert(14);
	n1.Insert(13);
	n1.InOrder(n1._root);
	cout << endl;
	struct BSTreeNode<int>* leftMax = n1._root;
	//leftMax->_key = 100;
	//n1.InOrder(n1._root);
	//cout << endl;
	//leftMax = leftMax->_left;
	//leftMax->_key = 110;
	//n1.InOrder(n1._root);
	//cout << endl;
	//leftMax->_left = nullptr;
	//n1.InOrder(n1._root);
	//cout << endl;
	n1.Erase(n1._root, 8);
	n1.InOrder(n1._root);
	cout << endl;
	//n1.Erase(n1._root, 14);
	//n1.InOrder(n1._root);
	//cout << endl;
	//n1.Erase(n1._root, 6);
	//n1.InOrder(n1._root);
	//cout << endl;
	//n1.Erase(n1._root, 10);
	//n1.InOrder(n1._root);
	//cout << endl;
}
#include<map>// key value
#include<set>
#include <utility>
int main()
{
	map<string,int> m;
	pair<string,int> p("apple",2);
	m.insert(p);
	m.insert(pair<string,int>("watermalen",1));//匿名对象
	m.insert(make_pair("banana",5));//函数调用 c++98
	m.insert({"strawberry",7});//多参数的隐式类型转换 C++11
	map<string,int>::iterator it=m.begin();
	while(it!=m.end())
	{
		cout<<it<<endl;
	}
	//test1();
	return 0;
}