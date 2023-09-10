#include <iostream>
using namespace std;
//int main()
//{
//	int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
//	for (auto e : arr)
//	{
//		cout << e << " ";
//	}
//
//	return 0;
//}
//void Print()
//{
//	cout << _year << _month << _day;
//}
class Date
{
public:
	Date(int year=2023 , int month = 9, int day = 9)//全缺省
	{
		_year = year;
		_month = month;
		_day = day;
		cout <<"时间："<< year << "-" << month << "-" << day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
//int main()
//{
//	Date d1(2020);  //传参从左向右
//	Date d2(2021, 1);
//	Date d3(2022, 1, 1);
//	return 0;
//}

int main()
{
	int a = 10;
	cout << &a << endl;
	a = 20;
	cout << &a << endl;
	const int b = 30;
	cout << &b << endl;
	return 0;
}
