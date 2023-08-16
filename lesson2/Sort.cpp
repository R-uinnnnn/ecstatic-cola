#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void Swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

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
        //gap=gap/2;
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
//选择排序 
void SelectSort(int* a,int n)
{
    //走一趟选出最小和最大，分别放到最左边和左右边，再往下走知道left和right相遇
     int left=0;
     int right=n-1;
     
     while(left<right)
     {
        int min=left;
        int max=left;
        for(int i=left;i<=right;i++)
        {
            if(a[i]<a[min])//找到最小位置，并记录
            {
                min=i;
            }
            if(a[i]>a[max])//找到最大位置，并记录
            {
                max=i;
            }
        }
        Swap(&a[min],&a[left]);
        Swap(&a[max],&a[right]);
        left++;
        right--;
     }
}
//冒泡排序
void BublueSort(int* a,int n)
{
    //将最大的数放到最后，通过两两比较
    int i=0,j=0;
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n-i;j++)
        {
            if(a[j-1]>a[j])
            {
                Swap(&a[j-1],&a[j]);
            }
        }
    }
}
//快排
void QuickSort(int* a,int n)
{



}
int main()
{
    int a[26]={12,33,41,5,32,43,13,1,23,6456,12,87,345,321,91,39,54,68,58,1,2,12,45,67,34,10};
    PrintSort(a,26);
    //InsertSort(a,5);
    //hellSort(a,10);
    //SelectSort(a,26);
    BublueSort(a,26);
    PrintSort(a,26);
    getchar();
    return 0;
}