#include<iostream>
#include<unordered_set>
#include<unordered_map>

using namespace std;
int main()
{
	unordered_set<int> s1;
	s1.insert(11);
	s1.insert(12);
	s1.insert(13);
	s1.insert(14);
	s1.insert(1);
	s1.insert(10);
	s1.insert(17);
	s1.insert(18);
	unordered_set < int>::iterator it = s1.begin();
	for (; it != s1.end(); it++)
	{
		cout << *it << endl;
	}
	getchar();
	return 0;
}
