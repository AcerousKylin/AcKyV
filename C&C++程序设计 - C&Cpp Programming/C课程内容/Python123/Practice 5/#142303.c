//计算所有约数
#include<stdio.h>
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        if (n%i==0&&i!=n)
            printf("%d ", i);
        if (n%i==0&&i==n)
            printf("%d", i);
    }
    return 0;
}