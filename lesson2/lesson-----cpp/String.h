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
		    my_strcpy(_str, str);//完成初始化工作
		}
		~string()
		{
			delete[] _str;
			_str = nullptr;
			_size = _capacity = 0;
			std::cout << "~string()" << std::endl;
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
				reserve(_size + len + 10);
			}
			my_strcpy(_str + _size, s);
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

		const char* c_str()const
		{
			return _str;
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
std::istream& operator>>(std::istream& out, abl::string& str)