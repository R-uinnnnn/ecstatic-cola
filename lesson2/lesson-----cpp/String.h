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
        typedef char* iterator;
        typedef const char* const_iterator;
        iterator begin()
        {
            return _str;
        }
        iterator end()//ָ��'\0'
        {
            return _str + _size;
        }
        const_iterator begin()const
        {
            return _str;
        }
        const_iterator end()const
        {
            return _str + _size;
        }
        /*string()  //����д���Ǵ����,��ʹc_str()Ϊnullptr,���⺯���ж��ڿ��ַ����Ĵ���������գ������ڴ��л���'\0'��
        :_size(0)
        ,_capacity(0)
        ,_str(nullptr)
        {

        }*/

        //    :_str(new char[strlen(str)+1])
        //    ,_size(strlen(str))
        //    ,_capacity(strlen(str))
        string(const char* str = "")
        {
            _size = strlen(str);
            _capacity = _size;
            _str = new char[_size + 1];
            strcpy_s(_str, str);
        }
        ~string()
        {
            delete[] _str;
            _str = nullptr;
            _size = _capacity = 0;
        }

        char& operator[](size_t pos)//���Զ���д
        {
            assert(pos >= 0 && pos < _size);
            return _str[pos];
        }
        char& operator[](size_t pos)const//ֻ�ܶ�
        {
            assert(pos >= 0 && pos < _size);
            return _str[pos];
        }
        void reserve(size_t n = 0)
        {
            char* tmp = new char[n];//�����¿ռ�n
            strcpy(tmp, _str);//��_str�����ݿ������¿ռ�
            delete[] _str;//�ͷ�_strԭ�пռ�
            _str = tmp;//��_str��ָ���Ϊtmp
            _capacity = n;
        }
        void push_back(char c)
        {
            size_t newcapacity = _capacity == 0 ? 6 : _capacity * 2;
            if (_size == _capacity)
            {
                reserve(newcapacity);
            }
            _capacity *= 2;
            _str[_size] = c;
            ++_size;
            _str[_size] = '\0';
        }
        string& insert(size_t pos, size_t n, char c)
        {
            assert(pos <= _size);
            if (_size + n > _capacity)
            {
                //reserve(capacity*2);
                reserve(_size + n);
            }
            _size += n;
            size_t end = _size + n;//��'\0'λ������n��λ��
            while (end >= pos + n)//�����posλ�ÿ�ʼ�����ƶ�n��λ�ã��͵�д��end>=pos����pos==0��������⣬��Ϊpos��size_t����
            {
                _str[end] = _str[end - n];
            }
            for (int i = pos; i < n; i++)
            {
                _str[i] = c;
            }
            return *this;
        }
        string& operator+= (const char* s)
        {
            size_t len = strlen(s);
            if (_size + len > _capacity)
            {
                //reserve(capacity*2);
                reserve(_size + len);
            }
            _size += len;
            for (int i = 0; i < len; i++)
            {
                _str[_size - len + i] = s[i];
            }
            _str[_size] = '\0';
        }
        string& append(const char* s)
        {
            size_t len = strlen(s);
            if (_size + len > _capacity)
            {
                //reserve(capacity*2);
                reserve(_size + len);
            }
            _size += len;
            _str += s;
            return *this;
        }

        const char* c_str()
        {
            return _str;
        }
    };
}