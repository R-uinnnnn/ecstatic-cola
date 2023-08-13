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
    int gap=n;
    while(gap>1)
    {
        //gap=n/2;
        gap=gap/3+1;//效率更高，gap表示跳跃步数
                    //gap值要改变
        for(int i=0;i<n-gap;i++)//多组一起比较
        {
            int end=i;
            int tmp=a[end+gap];//end位置的下一个
            while(end>=0)
            {
                if(tmp<a[end])
                {
                    a[end+gap]=a[end]; 
                }
                else
                {
                    break;
                }
                end-=gap;//前面数据是有序的
            }
            a[end+gap]=tmp;
        }
    }  
}
void PrintSort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void BublueSort(int* a,int n)
{


}
void QuickSort(int* a,int n)
{


    
}
int main()
{
    int a[10]={12,33,41,5,321,2,12,45,67,34};
    PrintSort(a,10);
    //InsertSort(a,5);
    ShellSort(a,10);
    PrintSort(a,10);
    getchar();
    return 0;
}