#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

/*
void Swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
*/
//插入排序
//升序排列

void InsertSort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        int end=i;//最后一个元素下标
        int tmp=a[end+1];//要插入的元素
        while(end>=0&&end+1<n) 
        {
            if(tmp<a[end])//如果插入元素tmp比前面数据大则交换,小的数据往前面流
            {
                a[end+1]=a[end];
                
            }
            else
            {
                break;
            }
            end--;//前面数据是有序的
        }
        a[end+1]=tmp;
    }

}

//希尔排序
void ShellSort(int* a,int n)
{
    int gap=n/3+1;//gap是跳跃步数，随着循环变化而慢慢变化 
    
}
void PrintSort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
int main()
{
    int a[15]={2,12,45,67,3,92,31,7,87,4,3,14,35,6};
    PrintSort(a,15);
    InsertSort(a,15);
    PrintSort(a,15);
    getchar();
    return 0;
}