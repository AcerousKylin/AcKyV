/*自然常数e可以用级数1+1/1!+1/2!+⋯+1/n!+⋯ 来近似计算
本题要求对给定的非负整数n，求该级数的前n+1项和*/
#include<stdio.h>
int main(void)
{
    int n, i;
    double item=1, sum=1, k;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        k = i;
        item *= 1/k;
        sum += item;
    }
    printf("%.8lf", sum);
    return 0;
}