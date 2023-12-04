#include <iostream>

using namespace std;
//#include "Vector_level.h"
#include "List_level.h"

//int main()
//{
//    Vector<int> v;
//    int a[10] = { 1,2,3,9,5,6,7,8,9,0 };
//    for (int i = 0; i < 10; i++)
//    {
//        v.Push_back(a[i]);//将数组a中元素输入到v中
//    }
//    const int x = 9;
//    int num = v.Count(x);
//	cout << num << endl;
//
//    return 0;
//}



int main()
{
    List<int> b;
    int a[10] = { 1,2,3,9,5,6,7,8,9,0 };
    for (int i = 0; i < 10; i++)
    {
        b.Push_back(a[i]);
    }
    int num = b.RemoveMin();
    cout << num << endl;
    return 0;
}
