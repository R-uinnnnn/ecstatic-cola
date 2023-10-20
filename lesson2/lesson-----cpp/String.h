#pragma
#include <assert.h>
#include <string.h>
#include <iostream>
#include<stdio.h>
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
	public:
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
		//char& operator[](size_t pos)
		//{
		//	assert(pos <= _size);
		//	return _str[pos];
		//}
		const char* c_str()const
		{
			return _str;
		}
	};
}