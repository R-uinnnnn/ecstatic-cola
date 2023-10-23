#pragma
#include <assert.h>
#include <string.h>
namespace abl
{
    class string
    {
    private:
        size_t _size;
        size_t _capacity;
        char* _str;
    public:
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
        char& operator[](size_t pos)
        {
            assert(pos<=_size);
            return _str[pos];
        }
        size_t size()const
        {
            return _size;
        }
    };
}