#include <iostream>
using namespace std;
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int QDtaType;
typedef struct QueueNode
{
    struct Queue *next;
    QDtaType data;
} QNode;

typedef struct Queue
{
    QNode *head;
    QNode *tail;

} Queue;
void QueueInit(Queue *p);
void QueueDestroy(Queue *p);

void QueuePush(Queue *p, QDtaType x);
void QueuePop(Queue *p);


int main()
{
    Queue p;

    getchar();
    return 0;
}