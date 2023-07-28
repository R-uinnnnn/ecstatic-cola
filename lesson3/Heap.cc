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

void Adjustup(HPDateType* a,int child)
{
    int parent=(child-1)/2;
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



















