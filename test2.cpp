

//队列
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
using namespace std;
//队列是先进先出，出去要头删数据，使用数组效率较低，因此用链表实现较优
typedef int QDataType;
typedef struct QListNode//队列
{
	struct QListNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;//多个数据，用结构体封装有利于参数传递
	int size;
	//只需要队尾插入，在队头删除给一个尾指针可以解决队列相关问题
}Queue;
void QueueInit(Queue* pq);//要改变的是结构体的成员(结构体Queue中的head和tail)，传一级指针即可
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, QDataType x);//尾部入队
void QueuePop(Queue* pq);//头部出队
int QueueSize(Queue* pq);
bool QueueEmpty(Queue* pq);
QDataType QueueFront(Queue* pq);//找队头元素
QDataType QueueBack(Queue* pq);//找队尾元素

void QueueInit(Queue* pq)//要改变的是结构体的成员(结构体Queue中的head和tail)，传一级指针即可
{
	assert(pq);
	pq->head =NULL;
    pq->tail = NULL;//不带头，直接置空即可
	pq->size = 0;
}
void QueueDestroy(Queue* pq)
{
	assert(pq);
	QNode* p = pq->head;
		
	while (p)
	{
		QNode* pnext = p->next;//放在循环内部，若p为NULL则不会进入循环
		free(p);
		p = pnext;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)//尾部入队
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc fail!");
        return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL&&pq->tail==NULL)//考虑插入数据是第一个的情形
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;//尾插
		pq->tail = newnode;//tail往后挪一位
	}

	pq->size++;
}
void QueuePop(Queue* pq)//头部出队
{
	assert(pq);
	assert(pq->size);
	QNode* hnext = pq->head->next;
	//free(pq->head);
	pq->head = hnext;
	pq->size--;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->size == 0;
}
QDataType QueueFront(Queue* pq)//找队头元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}
QDataType QueueBack(Queue* pq)//找队尾元素
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}

typedef struct {
    Queue q1;//空队列
    Queue q2;//非空队列
} MyStack;


MyStack* myStackCreate() {
    MyStack* obj=(MyStack*)malloc(sizeof(MyStack));
    if(obj==NULL)
    {
        perror("malloc");
        exit(-1);
    }
    QueueInit(&obj->q1);
    QueueInit(&obj->q2);
    return obj;
}

void myStackPush(MyStack* obj, int x) {
    Queue* empty=&obj->q1;
    Queue* unempty=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        empty=&obj->q2;
        unempty=&obj->q1;
    }
    QueuePush(unempty, x);
  
}

int myStackPop(MyStack* obj) {
    Queue* empty=&obj->q1;
    Queue* unempty=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        empty=&obj->q2;
        unempty=&obj->q1;
    }
    while(QueueSize(unempty)>1)
    {
        QueuePush(empty, QueueFront(unempty));
        QueuePop(unempty);
    }
    int top=QueueFront(unempty);
    QueuePop(unempty);
    return top;
}

int myStackTop(MyStack* obj) {
    Queue* empty=&obj->q1;
    Queue* unempty=&obj->q2;
    if(!QueueEmpty(&obj->q1))
    {
        empty=&obj->q2;
        unempty=&obj->q1;
    }
    return QueueBack(unempty);
}

bool myStackEmpty(MyStack* obj) {
    return QueueEmpty(&obj->q1)||QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    free(&obj->q1);
    free(&obj->q2);
    free(obj);
}

int main()
{
    MyStack* obj=myStackCreate();
    myStackPush(obj,1);
    myStackPush(obj,2);
    myStackPush(obj,3);
    myStackPush(obj,4);
    myStackPush(obj,5);
    int pop=myStackPop(obj);
    printf("%d\n",pop);
    int pop2=myStackPop(obj);
    printf("%d\n",pop2);
    myStackFree(obj);
    getchar();
    return 0;
}