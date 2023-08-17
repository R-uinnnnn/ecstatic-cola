#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
// 用动态数组的方式实现栈！！！

typedef int TypeData;
typedef struct Stack
{
    TypeData *a;  // 用动态数组，效率更高
    int top;      // 栈顶元素，可在该处插入和删除元素
    int capacity; // 栈的容量大小，若容量不够用则扩容
} ST;

// 声明
void Init(ST *p);
void Destroy(ST *p);

void Push(ST *p, TypeData x); // 只能在栈顶插入
void Pop(ST *p);              // 只能在栈顶删除
int Size(ST *P);              // 计算容量大小
bool Empty(ST *p);            // 判断栈是否为空

TypeData StackTop(ST *p); // 取出栈顶元素

// 定义
void Init(ST *p)
{
    // assert(p);
    TypeData *q = (TypeData *)malloc(sizeof(TypeData) * 6);
    if (q == NULL)
    {
        perror("malloc fail");
        exit(-1);
    }
    p->a = q;
    p->capacity = 6;
    p->top = 0; // 指向栈顶元素下一个
}
void Destroy(ST *p)
{
    assert(p);
    free(p->a);
    p->a = NULL;
    p->capacity = p->top = 0;
}

void Push(ST *p, TypeData x)
{
    assert(p);
    if (p->capacity == p->top)
    {
        TypeData *q = (TypeData *)realloc(p->a, sizeof(TypeData *) * p->capacity * 2);
        if (q == NULL)
        {
            perror("realloc fail!");
            exit(-1);
        }
        p->a = q;
        p->capacity = p->capacity * 2;
    }
    p->a[p->top] = x;
    p->top++;
}

bool Empty(ST *p)
{
    assert(p);
    return p->top == 0;
}
void Pop(ST *p)
{
    assert(p);
    assert(!Empty(p)); // 判断栈是否为空，不为空才可以删除数据
    p->top--;          // 删除
}
int Size(ST *p)
{
    assert(p);
    return p->top; // top指向栈顶元素下一个，top的大小就是栈里边数据个数
}

TypeData StackTop(ST *p)
{
    assert(p);
    return p->a[p->top - 1];
}

typedef struct {
    ST popst;//出队列栈
    ST pushst;//入队列栈
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj=(MyQueue*)malloc(sizeof(MyQueue));
    if(obj==NULL)
    {
        perror("malloc");
        exit(-1);;
    }
    Init(&obj->popst);
    Init(&obj->pushst);

    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    Push(&obj->pushst,x);

}

int myQueuePop(MyQueue* obj) {
    if(Empty(&obj->popst))
    {
        //倒数据
        while(Size(&obj->pushst)>0)
        {
            Push(&obj->popst,StackTop(&obj->pushst));
            Pop(&obj->pushst);
        }
    }
    int top=StackTop(&obj->popst);
    Pop(&obj->popst);
    return top;
}

int myQueuePeek(MyQueue* obj) {
    if(!Empty(&obj->pushst))
    {
        //倒数据
        while(Size(&obj->pushst)>0)
        {
            Push(&obj->popst,StackTop(&obj->pushst));
            Pop(&obj->pushst);
        }
    }
    return StackTop(&obj->popst);

}

bool myQueueEmpty(MyQueue* obj) {
    return Empty(&obj->pushst)&&Empty(&obj->popst);

}

void myQueueFree(MyQueue* obj) {
    Destroy(&obj->popst);
    Destroy(&obj->pushst);
    free(obj);
}

int main()
{
    MyQueue* obj=myQueueCreate();
    myQueuePush(obj,1);
    myQueuePush(obj,2);
    printf("%d\n",myQueuePeek(obj));
    printf("%d\n",myQueuePop(obj));
    printf("%d\n",myQueuePop(obj));
    getchar();
    return 0;
}