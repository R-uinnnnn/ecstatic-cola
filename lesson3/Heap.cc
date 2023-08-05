#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int HPDateType;
typedef struct Heap
{
    HPDateType* a;
    int size;
    int capacity;

}HP;
void HeapInit(HP* heap)
{
    HPDateType* tmp=(HPDateType*)malloc(sizeof(HPDateType)*6);
    if(tmp==NULL)
    {
        perror("malloc");
        return;
    }
    heap->a=tmp;
    heap->size=0;
    heap->capacity=6;
}
void Tmp(int* a,int* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}
void Adjustup(HPDateType* a,int child)//向上调整 大堆
{
    int parent=(child-1)/2;
    while(child>0)
    {
        if(a[parent]<a[child])
        {
            Tmp(&a[parent],&a[child]);
            child=parent;
            parent=(child-1)/2;
        }
        else//如果孩子<父亲，退出循环
        {
            break;
        }
    }
}
void HeapPush(HP* heap, HPDateType x)
{
    if(heap->size==heap->capacity)
    {
    HPDateType* tmp=(HPDateType*)realloc(heap->a,sizeof(HPDateType)*(heap->capacity)*2);
    if(tmp==NULL)
    {
        perror("malloc");
        return;
    }
    heap->a=tmp;
    heap->capacity*=2;
    }
    heap->a[heap->size]=x;
    Adjustup(heap->a,heap->size);
    heap->size++;

}
int main()
{
    HP heap;
    HeapInit(&heap);
    HeapPush(&heap,7);
    HeapPush(&heap,2);
    HeapPush(&heap,6);
    HeapPush(&heap,5);
    HeapPush(&heap,0);
    HeapPush(&heap,10);
    HeapPush(&heap,3);
    HeapPush(&heap,8);
    HeapPush(&heap,20);
    int i=0;
    while(i<heap.size)
    {
        printf("%d ",heap.a[i]);
        i++;
    }
    getchar();
    return 0;
}


















