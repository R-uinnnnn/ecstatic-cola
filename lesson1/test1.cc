#include <iostream>
#include <stdio.h>
#include <stdlib.h>

//计算n阶行列式的值
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define Max 100 //最多计算Max阶

/*
1.a[max][max]:  储存行列式
2.b[max]； 记录下标
3.n； 行列式的阶数
4.ped； 记录乘积
5.sum； 记录个乘积的和（记录结果）
6.c；记录逆序数
*/

int sum = 0; //定义全局变量，用于记录结果

//交换变量，用于全排列
void swap(int b[Max], int i, int j)
{
    int temp;
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
}

//判断n阶行列式相乘后的正负号
int mark(int b[Max], int n)
{
    int c = 0; //记录逆序数
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (b[i] > b[j])
            {
                c++;
            }
        }
    }
    if (c % 2 != 0)
        return 1;
}

//对全排列后的行列式进行计算
void Output(int a[Max][Max], int b[Max], int ped, int n)
{

    for (int i = 0; i < n; i++)
    {
        ped *= a[i][b[i]];
    }
    if (mark(b, n) == 1)
    {
        ped *= -1;
    }

    sum += ped;
}

//对行列式全排列
void cont(int a[Max][Max], int b[Max], int k, int n)
{
    int ped = 1;    //记录乘积
    if (k == n - 1) //全排列后进行计算
    {
        Output(a, b, ped, n);
    }
    else //全排列
    {
        for (int i = k; i < n; i++)
        {
            swap(b, i, k);
            cont(a, b, k + 1, n);
            swap(b, i, k);
        }
    }
}

//输入元素
void Input(int a[Max][Max], int n)
{

    for (int i = 0; i < n; i++)
    {
        printf("the %d values", i + 1);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

int main()
{

    system("color 9"); //控制颜色
    printf("input 'n':");
    int n; //记录需要求几阶行列式
    scanf("%d", &n);
    int a[Max][Max]; //储存行列式
    int b[Max];      //记录下标
    for (int i = 0; i < n; i++)
    {
        b[i] = i;
    }
    Input(a, n);
    cont(a, b, 0, n);
    system("color 3");
    printf("%d\n", sum);
    printf("!");
    return 0;
}

/*
int main()
{
    cout << "好的好的" << endl;
    getchar();
    return 0;
}
*/