#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDataType;
typedef struct QueueNode //数据节点
{
    struct QueueNode *next;
    QDataType data;
} QNode;

typedef struct Queue //封装首位节点指针，分别表示队尾和队头
{
    QNode *head;
    QNode *tail;
    int size;
} Queue;
//声明
void QueueInit(Queue *p);
void QueueDestroy(Queue *p);

void QueuePush(Queue *p, QDataType x); //入队，尾插
void QueuePop(Queue *p);               //出队，头删
int Queuesize(Queue *p);
bool QueueEmpty(Queue *p);

QDataType QueueFront(Queue *p);
QDataType QueueBack(Queue *p);
//定义
void QueueInit(Queue *p)
{
    assert(p);
    p->head = p->tail = NULL;
    p->size = 0;
}
void QueueDestroy(Queue *p)
{
    assert(p);
    QNode *cur = p->head;
    while (cur)
    {
        QNode *next = cur->next; //找到下一个数据
        free(cur);               //头删
        cur = next;              //跳转至下一个数据
    }
    p->head = p->tail = NULL;
    p->size = 0;
}

void QueuePush(Queue *p, QDataType x) //入队，尾插
{
    assert(p);
    QNode *newnode = (QNode *)malloc(sizeof(QNode)); //创建新节点
    if (newnode == NULL)
    {
        perror("malloc fail!");
        exit(-1);
    }
    newnode->next = NULL;
    newnode->data = x;

    if (p->head == NULL) //若没有存放数据
    {
        assert(p->tail != NULL);
        p->head = p->tail = newnode;
    }
    else //尾插
    {
        p->tail->next = newnode;
        p->tail = newnode;
    }
    p->size++;
}
void QueuePop(Queue *p) //出队，头删
{
    assert(p);
    assert(!QueueEmpty(p)); //队列为空，不能头删
    /*QNode *next = p->head->next;
    free(p->head);
    p->head = next;
    if (next == NULL)
    {
        p->tail = NULL; //防止tail出现野指针的问题
    }*/
    if (p->head->next = NULL) //队列中只有一个数据
    {
        free(p->head);
        p->head = p->tail = NULL;
    }
    else
    {
        QNode *next = p->head->next;
        free(p->head);
        p->head = next;
    }
    p->size--;
}
int Queuesize(Queue *p)
{
    assert(p);
    return p->size;
}
bool QueueEmpty(Queue *p)
{
    assert(p);
    return p->size == 0;
}

QDataType QueueFront(Queue *p)
{
    assert(p);
    assert(!QueueEmpty(p));
    return p->head->data;
}
QDataType QueueBack(Queue *p)
{
    assert(p);
    assert(!QueueEmpty(p));
    return p->tail->data;
}

int main()
{
    Queue p;
    QueueInit(&p);

    QueuePush(&p, 2);
    QueuePush(&p, 3);
    QueuePush(&p, 4);
    QueuePush(&p, 5);
    QueuePush(&p, 6);
    QueuePush(&p, 7);

    while (!QueueEmpty(&p))
    {
        printf("%d ", QueueFront(&p));
        QueuePop(&p);
    }

    QueueDestroy(&p);

    return 0;
}