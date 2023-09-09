#include <iostream>
using namespace std;
class Data
{
public:
    void Print()//会隐含一个this指针，指向对应的对象
    {
        cout<<_year<<"-"<<_month<<"-"<<_day<<endl;
    }
//我们不写，编译器自动生成一个
//无参构造函数
    /*Data()
    {
        cout<<"Data();"<<endl;
        _year=2023;
        _month=1;
        _day=1;
    }*/
//全缺省构造函数
    /*Data(int year=2020,int month=2,int day=2)
    {
        cout<<"Data(int year=2020,int month=2,int day=2);"<<endl;
        _year=year;
        _month=month;
        _day=day;
    }*/
private:
    int _year;
    int _month;
    int _day;

};
int main()
{
    Data d1;
    d1.Print();
    getchar();
    return 0;
}