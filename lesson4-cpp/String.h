
namespace STR
{
    class string
    {
    public:
    string (const char* str)
    :_str(new(strlen(str)+1))
    ,_size(strlen(str))
    ,_capacity(strlen(str))
    {
        
    }
    private:
        char* _str;
        size_t _size;
        size_t _capacity;
    };
}