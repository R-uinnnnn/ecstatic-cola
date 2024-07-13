
#include <vector>

using namespace std;
enum state
{
    EMPTY,
    EXIST,
    DELETE
};
template<class k,class v>
struct HASHDATE
{
    pair<k,v> _key;
    state _state;
};
template<class k,class v>
class HashTable
{
public:
    bool Insert(const pair<k,v>& key)
    {
        //线性探测，位置被占用
    }

private:
    vector<HASHDATE<k,v>> _table;
    size_t n;
};