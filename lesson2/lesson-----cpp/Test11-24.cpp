#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
using namespace std;

//��׺���ʽ=����׺���ʽ��+ - * / ���㣩
// 3+4*6-6/2=�� 3 4 6 * + 6 2 / -
// 1��������������
// 2���������
// 1��ջΪ��||��������ȼ�>ջ��   �������ջ
// 2��ջ��Ϊ��&&��������ȼ�<=ջ��   �������ջ
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




