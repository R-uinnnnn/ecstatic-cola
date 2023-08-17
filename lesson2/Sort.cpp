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
void BubbleSort(int* a,int n)
{
    for(int i=0;i<n-1;i++)//要走的躺数为n-1
    {
        int flag=1;
        for(int j=1;j<n-i;j++)
        {
            if(a[j-1]>a[j])
            {
                Swap(&a[j-1],&a[j]);
                flag=0;
            }
        }
        if(flag)//走一趟，一次都未交换，说明已经有序，跳出循环，提高效率
        {
            break;
        }
    }
}
/*
void BubbleSort(int* arr, int n)
{
    for(int i = 0; i < n - 1; i++)
    {
        int flags = 1;
        for (int j = i + 1; j < n; j++)
        {
            //从第一个位置开始存放数据，后面的位置与要存放数据位置的数据进行比较，将最小数据放到要存放的位置
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                flags = 0;
            }
        }

        if (flags)
        {
            break;
        }
    }
}*/
//快排
//1、预排序（递归手段）
//2、hoare版本  挖坑法  前后指针法                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
void QuickSort(int* a,int n)   
{
    int left;
    int right;



}
int main()
{
    int a[]={12,33,41,5,34,12,54,23,12,34,5,2,32};
    PrintSort(a,13);
    //InsertSort(a,5);
    //hellSort(a,10);
    //SelectSort(a,26);
    BubbleSort(a,13);
    PrintSort(a,13);
    getchar();
    return 0;
}