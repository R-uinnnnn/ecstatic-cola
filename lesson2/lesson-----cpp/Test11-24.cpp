#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//中缀表达式=》后缀表达式（+ - * / 运算）
// 3+4*6-6/2=》 3 4 6 * + 6 2 / -
// 1、是数字往后走
// 2、是运算符
// 1）栈为空||运算符优先级>栈顶   运算符入栈
// 2）栈不为空&&运算符优先级<=栈顶   运算符出栈
//

//int evalRPN(vector<string>& tokens)
//{
//
//	return 
//}

vector<string> to_exchange(vector<string>& v)
{
	int i = 0;
	stack<string>


}

int main()
{
	vector<string> v;
	v.push_back("3");
	v.push_back("+");
	v.push_back("4");
	v.push_back("*");
	v.push_back("6");
	v.push_back("-");
	v.push_back("6");
	v.push_back("/");
	v.push_back("2");
	vector<string> v2;
	v2 = to_exchange(v);

	return 0;
}




