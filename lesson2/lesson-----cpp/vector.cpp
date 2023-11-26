#include <iostream>
#include <vector>

#include <algorithm>

using namespace std;
#include "vector.h"
void test1()
{

	abl::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.resize(10, 7);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	for (auto it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
	v1.resize(7, 10);
	for (auto it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.resize(20, 100);
	for (auto it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	for (size_t i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << "   ";
	}

}
void test2()
{
	int a[5] = { 1,2,3,4,5 };
	vector<int> v1(a,a+5);
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	//v1.reserve(2);//修改容量<原有容量，容量不变
	//cout << v1.size() << endl;
	//cout << v1.capacity() << endl;
	//v1.reserve(20);
	//cout << v1.size() << endl;
	//cout << v1.capacity() << endl;
}
void test3()
{
	abl::vector<int>v;
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	abl::vector<int>v2;
	v2.push_back(11);
	v2.push_back(12);
	v2.push_back(13);
	v2.push_back(14);
	v2.push_back(15);
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
	v.pop_back();
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
	v.swap(v2);
	for (auto it : v)
	{
		cout << it << " ";
	}
	cout << endl;
	for (auto it : v2)
	{
		cout << it << " ";
	}
	cout << endl;
	abl::vector<int>::iterator it = v2.begin() + 2;
	v2.insert(it, 19);
	for (auto it : v2)
	{
		cout << it << " ";
	}
	v2.erase(v2.begin()+1);
	cout << endl;
	for (auto it : v2)
	{
		cout << it << " ";
	}
}
void test4()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	vector<int> v1(a, a + 9);
	for (auto it : v1)
	{
		cout << it << " ";
	}
	cout << endl;
}
int main()
{
	test4();
	return 0;
}