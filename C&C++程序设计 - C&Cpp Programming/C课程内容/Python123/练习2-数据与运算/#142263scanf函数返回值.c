/*
输入最多两个整数，
如果输入的是一个整数，就输出它的平方，
如果输入的是两个整数，就输出它们的乘积。
*/

#include<stdio.h>
int main(void)
{
    int a, b, c;
    c = scanf("%d %d", &a, &b);
    if (c==1)
        printf("%d", a*a);
    if (c==2)
        printf("%d", a*b);
    return 0;
}