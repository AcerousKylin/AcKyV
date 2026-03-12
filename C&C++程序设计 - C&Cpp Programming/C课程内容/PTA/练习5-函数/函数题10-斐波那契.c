#include <stdio.h>

int fib( int n );

int main()
{
    int n;

    scanf("%d", &n);
    printf("%d\n", fib(n));

    return 0;
}

/* 你的代码将被嵌在这里 */

int fib( int n )
{
    int i; int a[100];
    for (i=1; i<=n;i++)
    {
        if (i==1||i==2)
            a[i] = 1;
        else
            a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}