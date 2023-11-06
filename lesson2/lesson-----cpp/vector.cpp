#include <iostream>
#include <vector>
#include <algorithm>
#include "vector.h"
using namespace std;

int main()
{
	int a[5] = { 1,2,3,4,5 };
	abl::vector<int> v1;
	cout<<v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.reserve(2);//修改容量<原有容量，容量不变
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	v1.reserve(20);
	cout << v1.size() << endl;
	cout << v1.capacity() << endl;
	return 0;
}