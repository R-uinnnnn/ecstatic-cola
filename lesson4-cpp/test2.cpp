#include <iostream>
using namespace std;

class Data
{
public:
//类里边
    Data(int year,int month,int day)
    {
        _year=year;
        _month=month;
        _day=day;

    }

//private:
    int _year;
    int _month;
    int _day;

};

Data& operator>(Data& d1,Data& d2)
{
    if(&d1!=&d2)
    {
        d1._day=d2._day;
        d1._month=d2._month;
        d1._year=d2._year;
    }
    return d1;
}

Data& operator=(Data& d1,Data& d2)
{
    if(&d1!=&d2)
    {
        d1._day=d2._day;
        d1._month=d2._month;
        d1._year=d2._year;
    }
}

int main()
{
    Data d1(1,1,1);
    Data d2(2,2,2);
    d1=d2;
    cout<<d1._year<<d1._month<<d1._day<<endl;
    cout<<d2._year<<d2._month<<endl;
    getchar();
    return 0;
}