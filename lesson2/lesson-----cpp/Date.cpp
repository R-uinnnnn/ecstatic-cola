#include <iostream>
#include <stdio.h>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& cout, const Date& d);
public:

	// 获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		int Day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		int ndays = Day[month];
		if (month == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		{
			ndays++;
		}
		return ndays;
	}



	// 全缺省的构造函数

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	// 拷贝构造函数

  // d2(d1)

	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}



	// 赋值运算符重载

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		Date tmp(d);
		*this = tmp;
		return *this;
	}



	// 析构函数

	~Date()
	{
		_year = _month = _day = 0;
	}



	// 日期+=天数

	Date& operator+=(int day)
	{
		int ndays=GetMonthDay(_year, _month);
		if (_day + day > ndays)
		{
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
		}
		_day = _day + day - ndays;

	}



	// 日期+天数

	Date operator+(int day)
	{
		Date d = *this;
		int ndays = GetMonthDay(d._year,d. _month);
		while(d._day + day > ndays)
		{
			d._month++;
			if (d._month > 12)
			{
				d._month = 1;
				d._year++;
			}
			day -= ndays;
			ndays = GetMonthDay(d._year, d._month);
		}
		d._day += day;

		return d;
	}



	// 日期-天数

	Date operator-(int day)
	{
		Date d = *this;
		int ndays = GetMonthDay(d._year, d._month);
		while (d._day - day < 0)
		{
			d._month--;
			if (d._month <1 )
			{
				d._month = 12;
				d._year--;
			}
			day -= ndays;
			ndays = GetMonthDay(d._year, d._month);
		}
		d._day -= day;
		return d;
	}



	// 日期-=天数

	Date& operator-=(int day)
	{

	}



	// 前置++

	Date& operator++()
	{

	}



	// 后置++

	Date operator++(int)
	{

	}



	// 后置--

	Date operator--(int)
	{

	}



	// 前置--

	Date& operator--()
	{

	}



	// >运算符重载

	bool operator>(const Date& d)
	{

	}


	// ==运算符重载

	bool operator==(const Date& d)
	{

	}


	// >=运算符重载

	bool operator >= (const Date& d)
	{

	}

	// <运算符重载

	bool operator < (const Date& d)
	{

	}

	// <=运算符重载

	bool operator <= (const Date& d)
	{

	}

	// !=运算符重载

	bool operator != (const Date& d)
	{

	}

	// 日期-日期 返回天数

	int operator-(const Date& d)
	{

	}

private:
	int _year;
	int _month;
	int _day;
};
ostream& operator<<(ostream& cout,const Date& d)
{
	cout << d._year<<"-"<<d._month<<"-"<< d._day << endl;
	return cout;
}

int main()
{
	Date d1(2021,9,15);
	Date d2(2023, 11, 2);
	Date d3 = d2;
	Date d4 = d2 + 100;
	//cout << d3 << endl;
	//cout << d4 << endl;
	Date d5 = d2 - 50;
	cout << d4 << endl;
	return 0;
}