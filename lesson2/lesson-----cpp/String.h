#pragma once
#include <assert.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
//#include<string.h>
void my_strcpy(char* dest, const char* src) {
	while (*src != '\0') {
		*dest++ = *src++;
	}
	*dest = *src;   //拷贝\0
}

namespace abl
{

	class string
	{
		//这里暂时还用不到友元，因为在operator>>中并没有访问string的私有成员
	//friend std::istream& operator>>(std::istream& in, string& s);
	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		static size_t npos;
	public:
		
		typedef char* iterator;
		typedef const char* const_iterator;
		iterator begin()
		{
			return _str;//指向首元素
		}
		iterator end()
		{
			return _str + _size;//指向'\0'
		}
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		string(const char* str = "")
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_size + 1];
		    memcpy(_str, str,_size+1);//完成初始化工作
		}
		~string()
		{
			//std::cout <<"::"<< _str << std::endl;
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
			std::cout << "~string()" << std::endl;
		}
		//现代写法
	string(const string& s)
		:_str(nullptr)
		,_size(0)
		,_capacity(0)
	{
		string tmp(s._str);//调用默认构造函数string(const char* str = "")
		swap(tmp);//this可能没有初始化，析构的时候就会报错，因此要写参数初始化列表
	}
		//string(const string& s)
		//{
		//	_str = new char[s._capacity + 1];
		//	memcpy(_str, s._str, s._size);
		//	_size = s._size;
		//	_capacity = s._capacity;
		//}

		void swap(string& tmp)
		{
			std::swap(_str, tmp._str);
			std::swap(_size, tmp._size);
			std::swap(_capacity, tmp._capacity);
		}
		//现代写法
		string& operator= (string& s)
		{
			if (this != &s)
			{
				string tmp(s);//调用拷贝构造（深拷贝）
				swap(tmp);
			}
			return *this;
		}
		size_t size()const
		{
			return _size;
		}
		size_t capacity()const
		{
			return _capacity;
		}
		char& operator[](size_t pos)
		{
			assert(pos <= _size);
			return _str[pos];
		}
		void reserve(size_t n = 0)
		{
			//多留出一个空位给\0
			char* tmp = new char[n+1];//在堆区开辟空间，出函数不会销毁
			my_strcpy(tmp, _str);
			delete[] _str;
			_str = tmp;
			_capacity = n;
			//只改变了capacity，没有改变size，size不变
		}
		void push_back(char c)
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 6 : _capacity * 2);
			}
			_str[_size] = c;
			_size++;
			_str[_size] = '\0';
		}
		string& operator+= (char c)
		{
			push_back(c);
			return *this;
		}
		string& operator+= (const char* s)
		{
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len+10);
			}
			append(s);
			return *this;
		}
		string& append(const char* s)
		{
			size_t len = strlen(s);
			if (_size + len > _capacity)
			{
				reserve(_size + len + 1);
			}
			memcpy(_str + _size, s,len+1);
			_size += len;
			return *this;
		}
		string& insert(size_t pos, size_t n, char c)
		{
			assert(pos <= _size);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			size_t end = _size+n;
			for (; end>=pos+n; end--)
			{
				//abcd  size==4   pp  n==2  end==6  end-n==4
				_str[end] = _str[end-n];
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = c;
			}
			_size += n;
			return *this;

		}
		string& insert(size_t pos, const char* s, size_t n)
		{
			assert(pos <= _size);
			size_t len = strlen(s);
			if (_size + n > _capacity)
			{
				reserve(_size + n);
			}
			size_t end = _size + n;
			for (; end >= pos + n; end--)
			{
				//abcd  size==4   pp  n==2  end==6  end-n==4
				_str[end] = _str[end - n];
			}
			for (size_t i = 0; i < n; i++)
			{
				_str[pos + i] = s[i];
			}
			_size += n;
			return *this;
		}
		//string& erase(size_t pos = 0, size_t len = npos)
		//{

		//}
		bool operator<(string& s)const
		{
			size_t i1 = 0, i2 = 0;//遍历两个字符串4
			while (i1 < _size && i2 < s._size)
			{
				if (_str[i1] < s._str[i2])
				{
					return true;
				}
				else if (_str[i1] > s._str[i2])
				{
					return false;
				}
				else
				{
					i1++;
					i2++;
				}
			}
			//若循环正常进行结束，可能出现的情况：
			//hello hello     return false
			//hellowwww hello return false
			//hello hellowww  return true
			if (_size < s._size)
			{
				return true;
			}
			return false;
		}
		bool operator==(string& s)const
		{
			//std::cout << s._size << std::endl;
			if (_size != s._size)
			{
				return false;
			}
			return memcmp(_str, s._str, _size) == 0;
		}
		bool operator>(string& s)const
		{
			return !((*this < s) || (*this == s));
		}
		bool operator<=(string& s)const
		{
			return !(*this > s);
		}
		bool operator>=(string& s)const
		{
			return !(*this < s);
		}
		//string& operator= (const string& s)
		//{
		//	//开辟新空间，进行拷贝
		//	if (this != &s)//如果两个对象不相同
		//	{
		//		char* tmp = new char[s._capacity + 1];
		//		memcpy(tmp, s._str, s._size);
		//		delete[] _str;
		//		_str = tmp;
		//		_size = s._size;
		//		_capacity = s._capacity;
		//	}
		//	return *this;
		//}
		//void swap(string& str)
		//{
		//	
		//}
		//template<class T>
		//void swap(T m)
		//{
		//	T tmp = m;
		//	m = *this;
		//	*this = tmp;
		//}

		const char* c_str()const
		{
			return _str;
		}
		void clear()
		{
			_str[0] = '\0';
			_size = 0;
		}
	};
}
//std::ostream& operator<<(std::ostream& os, const abl::string& str)
//{
//	os << str._str << std::endl;
//	return os;
//}
size_t abl::string::npos = -1;//静态成员变量必须初始化，并且只能在类体外进行初始化
std::ostream& operator<<(std::ostream& out,const abl::string& str)
{
	for (auto ch : str)
	{
		out << ch;
	}
	//out << str.c_str();
	return out;
}
std::istream& operator>>(std::istream& in, abl::string& s)
{
	s.clear();
	char bucket[128];//相当于一个桶，装满了再往s里边加，减少了开辟空间的次数，充分利用空间
	char c=in.get();
	int i = 0;
	while (c != ' ' && c != '\n')
	{
		bucket[i] = c;
		i++;
		
		if (i == 127)
		{
			bucket[i] = '\0';//operator+=中要计算bucket的长度，以'\0'为终止条件，因此要在最后加上
			s += bucket;
			i = 0;//重新往buckt里边放入数据
		}
		c = in.get();
	}
	if (i != 0)
	{
		bucket[i] = '\0';//...
		s += bucket;
	}

	return in;
}