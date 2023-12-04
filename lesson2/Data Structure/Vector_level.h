#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<stdlib.h>

template<class T>
class Vector
{
private:
	T* data;						//数组指针
	int theSize;					//数组中的数据元素个数
	int theMax;						//数组容量
	void Error(const char* cs)const { cout << cs << endl; exit(1); }//错误信息报告
public:
	explicit Vector(int n = 0) :theSize(0), theMax(n + SPARE_MAX)
	{
		if (theMax > 0) data = new T[theMax];
	}
	Vector(const Vector<T>& v) :data(NULL), theMax(0) { operator=(v); }//拷贝构造函数
	~Vector(void) { delete[]data; }
	Vector<T>& operator=(const Vector<T>& v)
	{
		if (theMax != v.Max())
		{
			delete[]data;
			theMax = v.theMax;
			data = new T[theMax];
		}
		theSize = v.Size();
		for (int i = 0; i < theSize; i++)
			data[i] = v.data[i];
		return(*this);

	}
		//拷贝赋值函数
	enum { SPARE_MAX = 16 };

	bool Empty(void)const { return(theSize == 0); }	//判空
	int Size(void)const { return(theSize); }		//求数据个数
	void Push_back(const T& item)
	{
		if (theSize == theMax)			//如果空间数据已满，就要先扩大容量
			Reserve(2 * theMax + 1);
		data[theSize++] = item;		//插入元素到尾部，数据个数增1
	}
		
	T& operator[](int id) 
	{
		return(data[id]); 
	}
	//迭代器类型
	typedef T* iterator;						//迭代器
	typedef const T* const_iterator;			//指向const常量的迭代器
	iterator begin()
	{
		return data;
	}//使迭代器指向容器起始位置
	const_iterator begin()const { return data; }
	iterator end() { return (&data[theSize]); }	//使迭代器指向容器结束位置
	const_iterator end()const { return (&data[theSize]); }
	void Reserve(int newMax)
	{
		if (newMax < theSize)
			return;
		T* old = data;
		data = new T[newMax];
		for (int i = 0; i < theSize; i++)
			data[i] = old[i];
		theMax = newMax;
		delete[]old;
	}
	int Count(const T& item)const
	{
		int num = 0;
		const_iterator it = begin();
		while (it != end())
		{
			if (*it == item)
				num++;
			++it;
		}
		return num;
	}


};




#endif