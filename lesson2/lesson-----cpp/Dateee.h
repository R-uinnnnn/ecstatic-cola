#pragma once
#ifndef __DATE_HPP__
#define __DATE_HPP__
#include <assert.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <ostream>

class Date {
public:
    friend std::ostream& operator<<(std::ostream& out, const Date& d);
    friend std::istream& operator>>(std::istream& in, Date& d);
    // Ĭ�Ϲ���
    Date(long long year = 1, short month = 1, short day = 1) {
        if (month <= 0 || month > 12) {
            std::cerr << "�Ƿ�����!, �·ݲ��Ϸ�, month: " << month << std::endl;
            exit(1);
        }
        else {
            if (day < 1 || day > GetMonthDay(year, month)) {
                std::cerr << "�Ƿ�����!, �������Ϸ�, day: " << day << std::endl;
                exit(1);
            }
        }

        _year = year;
        _month = month;
        _day = day;
    }

    Date(Date&&) = default;
    Date(const Date& d1) { Swap(d1); }
    Date& operator=(const Date& d1) {
        Swap(d1);

        return *this;
    }

    ~Date() {}

    static short GetMonthDay(long long year, short month) {
        static const short month_arr[13]{ 0,  31, 28, 31, 30, 31, 30,
                                         31, 31, 30, 31, 30, 31 };
        short day = month_arr[month];

        // 1. ֻ���� 2 �·ݲ���Ҫ�ж��Ƿ�������
        // 2. ������жϹ���
        //    2.1 ��ͨ���ܱ� 4 ��������ͨ�겻�ܱ� 100 ����
        //    2.2 �������ܱ� 400 �����ľ������꣬ �� 2000 ��������� 1900 �겻������
        if (month == 2 && ((!(year % 4) && year % 100) || !(year % 400))) {
            day++;
        }

        return day;
    }

    Date& operator++() {
        (*this) += 1;

        return *this;
    }

    Date operator++(int) {
        Date tmp(*this);
        (*this) += 1;

        return tmp;
    }

    Date& operator+=(long long day) {
        if (day < 0) {
            return *this -= -day;
        }

        long long day_tmp = _day;
        // _day += day;
        // while (_day > GetMonthDay(_year, _month)) {
        //   _day -= GetMonthDay(_year, _month);
        //   _month++;
        //   if (_month == 13) {
        //     ++_year;
        //     _month = 1;
        //   }
        // }

        // ��Ϊ _day �� short ���ͻ������������ day_tmp ȥ������ٷ���
        day_tmp += day;
        while (day_tmp > GetMonthDay(_year, _month)) {
            day_tmp -= GetMonthDay(_year, _month);
            _month++;
            if (_month == 13) {
                ++_year;
                _month = 1;
            }
        }

        _day = day_tmp;

        return *this;
    }

    Date operator+(long long day) {
        Date tmp(*this);
        tmp += day;

        return tmp;
    }

    Date& operator--() {
        (*this) -= 1;

        return *this;
    }

    Date operator--(int) {
        Date tmp(*this);

        (*this) -= 1;

        return tmp;
    }

    Date& operator-=(long long day) {
        if (day < 0) {
            return *this += -day;
        }

        long long day_tmp = _day;
        day_tmp -= day;
        // _day -= day;
        //
        // while (_day <= 0) {
        //   --_month;
        //   if (_month == 0) {
        //     _month = 12;
        //     _year--;
        //   }
        //
        //   _day += GetMonthDay(_year, _month);
        // }

        // ��Ϊ _day �� short ���ͻ������������ day_tmp ȥ������ٷ���
        while (day_tmp <= 0) {
            --_month;
            if (_month == 0) {
                _month = 12;
                _year--;
            }

            day_tmp += GetMonthDay(_year, _month);
            std::cout << GetMonthDay(_year,_month) << std::endl;
        }

        _day = day_tmp;

        return *this;
    }

    Date operator-(long long day) {
        Date tmp(*this);
        tmp -= day;

        return tmp;
    }

    long long operator-(const Date& d) {
        long long day = DateSubDate(d);

        return day;
    }

    long long DateSubDate(const Date& d) {
        Date max_date(*this);
        Date min_date(d);
        if ((*this) < d) {
            max_date = d;
            min_date = (*this);
        }

        long long day = 0;
        while (max_date != min_date) {
            day++;
            min_date++;
        }

        return day;
    }

    bool operator==(const Date& d) {
        return (_year == d._year) && (_month == d._month) && (_day == d._day);
    }

    bool operator!=(const Date& d) { return !((*this) == d); }

    bool operator<(const Date& d) {
        if (_year != d._year) {
            return _year < d._year;
        }

        if (_month != d._month) {
            return _month < d._month;
        }

        return _day < d._day;
    }

    static void Print(long long day) {
        long long day_tmp = day;
        long long year_tmp = day_tmp / 365;
        day_tmp %= 365;
        short month_tmp = day_tmp / 30;
        day_tmp %= 30;

        printf("���: %d �� == %d ������ == %d����%d�� == %ld��%d����%d��\n",
            abs(day), abs(day / 7), abs(day / 30), abs(day % 30), abs(year_tmp),
            abs(month_tmp), abs(day_tmp));
    }

    bool operator>(const Date& d) { return !((*this) <= d); }

    bool operator<=(const Date& d) { return (*this) < d || (*this) == d; }

    bool operator>=(const Date& d) { return !((*this) < d); }

    void Swap(const Date& d1) {
        _year = d1._year;
        _month = d1._month;
        _day = d1._day;
    }

    void Print() { printf("%ld��%d��%d��\n", _year, _month, _day); }

private:
    long long _year;
    short _month;
    short _day;
};

std::ostream& operator<<(std::ostream& out, const Date& d) {
    out << d._year << "��" << d._month << "��" << d._day << "��" << std::endl;

    return out;
}

std::istream& operator>>(std::istream& in, Date& d) {
    long long year;
    short month;
    short day;

    in >> year >> month >> day;

    if (month > 0 && month < 13) {
        d._year = year;
        d._month = month;
        d._day = day;
    }
    else {
        std::cerr << "�Ƿ�����" << std::endl;
        assert(false);
    }

    return in;
}

#endif // !__DATE_HPP__