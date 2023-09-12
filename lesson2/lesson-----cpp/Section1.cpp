#include <iostream>
using namespace std;
class Data
{
public:
    void Print()//������һ��thisָ�룬ָ���Ӧ�Ķ���
    {
        cout << _year << "-" << _month << "-" << _day << endl;
    }
    //���ǲ�д���������Զ�����һ��
    // �������ȱʡֵ���൱�ڱ��������������´���
    Data()
    {
        _year = 1;//������ȱʡֵ
        _month = 1;
        _day = 1;
    }
        /*Data()
        {
            cout<<"Data();"<<endl;
            _year=2023;
            _month=1;
            _day=1;
        }*/
        //ȫȱʡ���캯��
            /*Data(int year=2020,int month=2,int day=2)
            {
                cout<<"Data(int year=2020,int month=2,int day=2);"<<endl;
                _year=year;
                _month=month;
                _day=day;
            }*/
private:
    int _year=1;
    int _month=1;
    int _day=1;

};
//int main()
//{
//    Data d1;
//    d1.Print();
//    return 0;
//}