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
    
//    :_str(new char[strlen(str)+1])
//    ,_size(strlen(str))
//    ,_capacity(strlen(str))
    string(const char* str="")
    {
        _size=strlen(str);
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
    const char* c_str()const
    {
        return _str;
    }
    char& operator[](size_t pos)//可以读和写
    {
        assert(pos>=0&&pos<_size);
        return _str[pos];
    }

    const char& operator[](size_t pos)const//只能读
    {
        assert(pos>=0&&pos<_size);
        return _str[pos];
    }
    void reserve (size_t n = 0)
    {
        if(n>capacity)
        {
        char* tmp=new char[n];//开辟新空间n
        strcpy(tmp,_str);//将_str的数据拷贝到新空间
        delete[] _str;//释放_str原有空间
        _str=tmp;//将_str的指向改为tmp
        _capacity=n;
        }
    }
    void push_back(char c)
    {
        size_t newcapacity = _capacity==0 ? 6 : _capacity*2;
        if(_size==_capacity)
        {
            reserve(newcapacity);
        }
        _capacity*=2;
        _str[_size]=c;
        ++_size;
        _str[_size]='\0';
    }
    string& insert(size_t pos, size_t n, char c)
    {
        assert(pos<=_size);
        if(_size+n>_capacity)
        {
            //reserve(capacity*2);
            reserve(_size+n);
        }
        _size+=n;
        size_t end=_size+n;//从'\0'位置往后n个位置
        while(end>=pos+n)//如果从pos位置开始往后移动n个位置，就得写成end>=pos但当pos==0会出现问题，因为pos是size_t类型
        {
            _str[end]=_str[end-n];
        }
        for(int i=pos;i<n;i++)
        {
            _str[i]=c;
        }
        return *this;
    }
/*
    string& operato+=(const char* s)
    {
        /*size_t len=strlen(s);
        if(_size+len>_capacity)
        {
            //reserve(capacity*2);
            reserve(_size+len);
        }
        _size+=len;
        for(int i=0;i<len;i++)
        {
            _str[_size-len+i]=s[i];
        }
        _str[_size]='\0';*/
        append(s);
        return *this;

    }

    string& append (const char* s)
    {
        size_t len=strlen(s);
        if(_size+len>_capacity)
        {
            //reserve(capacity*2);
            reserve(_size+len);
        }
        _size+=len;
        _str+=s;
        return *this;
    }
*/
    

    private:
        size_t _size;
        size_t _capacity;
        char* _str;
    };
}