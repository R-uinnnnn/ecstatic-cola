#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//插入排序
void Swap(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void InsertSort(int* a,int n)
{
    for(int i=0;i<n;i++)
    {
        int end=i;//最后一个元素下标
        int tmp=a[end+1];//要插入的元素
        while(end>0)
        {
            if(tmp>a[end])//如果插入元素tmp比前面数据大，则交换
            {
                Swap(&tmp,&(a[end]));
            }
            end--;//确保每个元素都比较了
        }
    }

}

//希尔排序
void ShellSort(int* a,int n)
{

    
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
    int a[10]={2,7,4,8,9,3,4,0,1,5};
    PrintSort(a,10);
    InsertSort(a,10);
    PrintSort(a,10);
    getchar();
    return 0;
}