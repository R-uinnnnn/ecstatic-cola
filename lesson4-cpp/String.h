#include <assert.h>
namespace STR
{
    class string
    {
    public:
    typedef char* iterator;
    typedef const char* const_iterator;
    iterator begin()
    {
        return _str;
    }
    iterator end()//指向'\0'
    {
        return _str+_size;
    }
    const_iterator begin()const
    {
        return _str;
    }
    const_iterator end()const
    {
        return _str+_size;
    }
    /*string()  //这种写法是错误的,会使c_str()为nullptr,而库函数中对于空字符串的处理是输出空（但是内存中会存放'\0'）
    :_size(0)
    ,_capacity(0)
    ,_str(nullptr)
    {

    }*/
    string(const char* str="")
//    :_str(new char[strlen(str)+1])
//    ,_size(strlen(str))
//    ,_capacity(strlen(str))
    :_size(strlen(str))
    {
        _capacity=_size;
        _str=new char[_size+1];
        strcpy(_str,str);
    }
    ~string()
    {
        delete[] _str;
        _str=nullptr;
        _size=_capacity=0;
    }
    
    char& operater[](size_t pos)//可以读和写
    {
        assert(pos>=0&&pos<_size);
        return _str[pos];
    }
    char& operater[](size_t pos)const//只能读
    {
        assert(pos>=0&&pos<_size);
        return _str[pos];
    }
    void push_back(char c)
    {
        
    }

    const char* c_str()
    {
        return _str;
    }
    private:
        size_t _size;
        size_t _capacity;
        char* _str;
    };
}