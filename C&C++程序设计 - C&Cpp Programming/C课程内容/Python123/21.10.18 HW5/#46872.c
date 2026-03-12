//阶乘
#include<stdio.h>
int main(void)
{
    int n, i;
    double factorial=1; //这玩意太大了XD
    scanf("%d", &n);
    if (n>0)
    {
        for (i=2; i<=n; i++)
        {
            factorial *= i;
        }
    }
    else if (n==0)
        factorial = 1;
    else printf("Invalid Value");
    printf("%.0lf", factorial);
    return 0;
}