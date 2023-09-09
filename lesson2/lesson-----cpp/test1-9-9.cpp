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
class Date
{
public:
	//Date(int year , int month = 9, int day = 9)
	//{
	//	_year = year;
	//	_month = month;
	//	_day = day;
	//	cout <<"ʱ�䣺"<< year << "-" << month << "-" << day << endl;
	//}
	void Print()
	{
		cout << _year << _month << _day;
	}
private:
	int _year=1;
	int _month=2;
	int _day=3;
};
int main()
{
	Date d1;
	d1.Print();
	return 0;
}