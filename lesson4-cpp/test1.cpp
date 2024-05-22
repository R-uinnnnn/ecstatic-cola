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

/*

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
	int t=0;
	int target=-t;
	cout<<target;
    getchar();

    return 0;
}
*/

#include<iostream>
using namespace std;
char X[100];
char Y[100];
int c[100][100] = {0};//用于储存X和Y的最长公共子序列的长度
int b[100][100] = {0};//记录X和Y的最长公共子序列的位置
void LCSLength(int m,int n,char X[],char Y[],int c[][100],int b[][100])
{
	int i,j;
	//先把第一行和第一列的位置全部变为0
	for(i=1;i<=m;i++)
		c[i][0] = 0;
	for(i=1;i<=n;i++)
		c[0][i] = 0;
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(X[i]==Y[j])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j] = 1;//表示最后一个元素相等
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
		}
	}
}
void LCS(int i,int j,char X[],int b[][100])
{
	if(i==0 ||j==0)
		return ;
	if(b[i][j]== 1)
	{
		LCS(i-1,j-1,X,b);
		cout<<X[i];
	}
	else if(b[i][j]==2)
	{
		LCS(i-1,j,X,b);
	}
	else 
		LCS(i,j-1,X,b);
}
int main(void)
{
	int i,j,n,m;
	//先输入x序列的长度在输入y序列的长度
	//cout<<"先输入x的长度在输入y的长度"<<endl;
	cin>>m>>n;
	for(i=1;i<=m;i++)//输入x序列
		cin>>X[i];
	for(i=1;i<=n;i++)//输入y序列
		cin>>Y[i];
	cout<<endl;
	LCSLength(m,n,X,Y,c,b);
	cout<<"最长子序列的长度为："<<c[m][n];
	cout<<"最长子序列为：";
	LCS(m,n,X,b);
	cout<<endl;
	return 0;
}

