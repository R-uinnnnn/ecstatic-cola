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
    state _state=EMPTY;
};
template<class k,class v>
class HashTable
{
public:
    /*bool Insert(const pair<k,v>& kv)
    {
        //线性探测，位置被占用继续往后找
        size_t hashi=kv._first%_table.size();
        while(kv._state!=EMPTY)
        {
            //if(kv._state)
        }

    }*/

private:
    vector<HASHDATE<k,v>> _table;
    size_t n;
};