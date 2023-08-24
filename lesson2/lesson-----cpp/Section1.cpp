#include <stdio.h>
#include <stdlib.h>

int m = 20;//全局变量
//局部变量优先访问
int main()
{
    int m = 10;//局部变量
    printf("%d\n ", m);
    // :: 为域访问限定符
    printf("%d ", ::m);
    //当加上之后， 左边是空白表示是全局域                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                   
    return 0;
}