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

//private:
    int _year;
    int _month;
    int _day;

};
int main()
{
    Data d1;
    Data d2;
    cout<<d1._year<<d1._month<<d1._day<<endl;
    getchar();
    return 0;
}