/*#include <iostream>
namespace A
{
    int a=100000000;
}

//using namespace A;//展开命名空间
using A::a; 
int main() 
{
    int a=20;
    std::cout<< A::a << a << std::endl;
    getchar();
    return 0;
}
*/

#include <iostream>
#include <stdio.h>
using namespace std;
int search_bin(int arr[],int key,int sz)
{
	int left = 0; //左下标
	int right = sz - 1;//右下标
	int mid = 0;
	int k = key;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else
		{
			printf("找到了，下标为：%d\n", mid);
			break;
		}
		
		

		
	}
	if (left > right)
	{
		printf("没找到\n");
        return -1; 
	}
    cout<<mid<<endl;

    return 0;
}
int main()
{
    int arr[8]={1,3,5,7,8,9,10,15};
    int sz = sizeof(arr) / sizeof(arr[0]);
    search_bin(arr,7,sz);
    getchar();

    return 0;
}