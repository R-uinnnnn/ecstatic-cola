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


	void swap(const Date& d)
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
		swap(tmp);
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
		int ndays = GetMonthDay(_year, _month);
		while (_day + day > ndays)//15+15=30>28
		{
			_month++;
			if (_month > 12)
			{
				_month = 1;
				_year++;
			}
			day -= ndays;
			ndays = GetMonthDay(_year, _month);
		}
		_day += day;
		return *this;

	}



	// 日期+天数

	Date operator+(int day)
	{
		Date d = *this;//用已存在的对象初始化一个不存在的对象，调用拷贝构造函数
		//int ndays = GetMonthDay(d._year,d. _month);
		//while(d._day + day > ndays)//15+15=30>28
		//{
		//	d._month++;
		//	if (d._month > 12)
		//	{
		//		d._month = 1;
		//		d._year++;
		//	}
		//	day -= ndays;
		//	ndays = GetMonthDay(d._year, d._month);
		//}
		//d._day += day;
		/*用拷贝构造（现代方式实现）
		Date d(*this);
		d+=day;
		*/
		d += day;
		return d;

	}

	// 日期-=天数

	Date& operator-=(int day)
	{
		int ndays = GetMonthDay(_year, _month);
		while (_day - day < 0)
		{
			_month--;
			if (_month < 1)
			{
				_month = 12;
				_year--;
			}
			day -= ndays;
			ndays = GetMonthDay(_year, _month);
		}
		_day -= day;
	}

	// 日期-天数

	Date operator-(int day)
	{
		Date d = *this;
		//int ndays = GetMonthDay(d._year, d._month);
		//while (d._day - day < 0)
		//{
		//	d._month--;
		//	if (d._month <1 )
		//	{
		//		d._month = 12;
		//		d._year--;
		//	}
		//	day -= ndays;
		//	ndays = GetMonthDay(d._year, d._month);
		//}
		//d._day -= day;
		d -= day;
		return d;
	}


	// 前置++

	Date& operator++()
	{
		*this += 1;
		return *this;
	}



	// 后置++

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}



	// 后置--

	Date operator--(int)
	{
		*this -= 1;
		return *this;
	}



	// 前置--

	Date& operator--()
	{
		Date tmp(*this);
		*this -= 1;
		return *this;
	}



	// >运算符重载

	bool operator>(const Date& d)
	{
		if (_year != d._year)
		{
			return _year > d._year;
		}
		if (_month != d._month)
		{
			return _month > d._month;
		}
		return _day > d._day;
	}


	// ==运算符重载

	bool operator==(const Date& d)
	{
		return (_year == d._year) && (_month == d._month) && (_day == d._day);
	}


	// >=运算符重载

	bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}

	// <运算符重载

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=运算符重载

	bool operator <= (const Date& d)
	{
		return (*this < d) || (*this == d);
	}

	// !=运算符重载

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// 日期-日期 返回天数

	long long operator-(const Date& d)
	{
		Date  max_date = *this;
		Date min_date = d;
		if (*this < d)
		{
			max_date = d;
			min_date = *this;
		}
		long long day = 0;
		while (max_date!=min_date)
		{
			day++;
			min_date++;
		}

		return day;
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
	Date d1(2022,11,15);
	Date d2(2023, 11, 2);
	Date d6(2023, 11, 2);
	//Date d3 = d2;
	//Date d4 = d2 + 100;
	//cout << d3 << endl;
	//cout << d4 << endl;
	//Date d5;
	//d5 = d2 - 50;
	//cout<<d2 - 50<<endl;
	//cout << d5 << endl;
	cout << (d1 > d2)<<endl;
	cout << (d1 == d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d2 == d6) << endl;
	int days = d6 - d1;
	cout << days << endl;
	return 0;
}
