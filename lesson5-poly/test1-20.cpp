#include <iostream>
using namespace std;

//多态
class Person
{
public:
    virtual void max()
    {
        cout<<"Person called"<<endl;
    }

};
class Student:public Person
{
public:
    virtual void max()//1、虚函数重写（父类必须有virtual 子类可以省略 + 函数名/参数/返回值类型必须相同）
    {
        cout<<"Student called"<<endl;
    }

};
void call(Person& it)//通过基类（父类）的指针或引用调用虚函数
{
    it.max();
}

int main()
{
    Person p1;
    call(p1);
    Student s1;
    call(s1);
    getchar();
    return 0;
}