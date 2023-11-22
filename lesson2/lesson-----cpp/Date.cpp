#include <iostream>
#include <stdio.h>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& cout, const Date& d);
public:

	// ��ȡĳ��ĳ�µ�����
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

	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}



	// �������캯��

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
	// ��ֵ���������

  // d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d)
	{
		Date tmp(d);
		swap(tmp);
		return *this;
	}



	// ��������

	~Date()
	{
		_year = _month = _day = 0;
	}



	// ����+=����

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

	// ����+����

	Date operator+(int day)
	{
		Date d = *this;//���Ѵ��ڵĶ����ʼ��һ�������ڵĶ��󣬵��ÿ������캯��
		d += day;
		return d;

	}

	// ����-=����

	Date& operator-=(int day)
	{
		
		while (_day - day <= 0)//��_day==dayʱҲҪ����ѭ������Ȼ����4��0�����ƵĲ��Ϸ�����
		{
			_month--;

			if (_month < 1)
			{
				_month = 12;
				_year--;
				
			}
			int ndays = GetMonthDay(_year, _month);
			//�������·�֮����ӳ�����Ӧ����������Ϊ����Ҫʹ��ǰһ��������
			//cout << ndays << endl;
			day -= ndays;
		}
		_day -= day;
		return *this;
	}

	// ����-����

	Date operator-(int day)
	{
		Date d (*this);
		d -= day;
		return d;
	}
	// ǰ��++

	Date& operator++()
	{
		*this += 1;
		return *this;
	}

	// ����++

	Date operator++(int)
	{
		Date tmp(*this);
		*this += 1;
		return tmp;
	}


	// ǰ��--

	Date& operator--()
	{
		*this -= 1;
		return *this;
	}


	// ����--

	Date operator--(int)
	{
		Date tmp(*this);
		*this -= 1;
		return tmp;
	}






	// >���������

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


	// ==���������

	bool operator==(const Date& d)
	{
		return (_year == d._year) && (_month == d._month) && (_day == d._day);
	}


	// >=���������

	bool operator >= (const Date& d)
	{
		return (*this > d) || (*this == d);
	}

	// <���������

	bool operator < (const Date& d)
	{
		return !(*this >= d);
	}

	// <=���������

	bool operator <= (const Date& d)
	{
		return (*this < d) || (*this == d);
	}

	// !=���������

	bool operator != (const Date& d)
	{
		return !(*this == d);
	}

	// ����-���� ��������

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
void test1()
{
	Date d1(2023, 11, 20);
	Date d2(2023, 11, 20);
	Date d3(2023, 11, 2);
	//cout << (d1 - d2) << endl;
	int sub1 = (d1++) - d3;//2023.11.20-2023.11.2
	int sub2 = (++d2) - d3;//2023.11.21-2023.11.2
	cout << sub1 << endl;
	cout << sub2 << endl;
	Date d4(2022, 10, 28);
	Date d5(2022, 10, 28);
	Date d6(2023, 7, 30);
	int sub3 = (d4--) - d6;
	int sub4 = (--d4) - d6;
	cout << sub3 << endl;
	cout << sub4 << endl;
}
int main()
{
	test1();

	return 0;
}
