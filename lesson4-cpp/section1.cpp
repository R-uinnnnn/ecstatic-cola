#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;//输入输出流展开
/*
int m=20;//全局变量
//局部变量优先访问
int main()   
{
    int m=10;//局部变量
    printf("%d ",m);
    getchar();
    return 0;
}
*/
typedef struct Seqlist
{
    int* a;
    int size;
    int capacity;

}Seqlist;
int& getvalue(Seqlist* p,int pos)
{
    return p->a[pos];
}
void SLInit(Seqlist* p)
{
    p->a=(int*)malloc(sizeof(int)*10);
    p->size=0;
    p->capacity=10;
}
void SLPushBack(Seqlist* p,int x)
{
    if(p->size==p->capacity)
    {
        p->a=(int*)realloc(p->a,sizeof(int)*p->size*2);
    }
     
}
int main()
{
    Seqlist p;
    SLInit(&p);
    int x=getvalue(&p,1);
    cout<<x<<endl;
    int y=getvalue(&p,3);
    cout<<y<<endl;
    getchar();
    return 0;
}
