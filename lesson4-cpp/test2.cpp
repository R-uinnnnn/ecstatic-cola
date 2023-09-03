#include <iostream>
using namespace std;

class Data
{
public:
    Data()
    {
        _year=2;
        _month=2;
        _day=2;
    }
    Data(int year,int month=1,int day=1)
    {
        _year=year;
        _month=month;
        _day=day;
    }
private:
    int _year;
    int _month;
    int _day;

};
int main()
{
    Data d1(1);
    Data d2;
    getchar();
    return 0;
}