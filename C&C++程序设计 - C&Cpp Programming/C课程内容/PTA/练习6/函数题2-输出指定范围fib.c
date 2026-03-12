#include <stdio.h>

int fib( int n );
void PrintFN( int m, int n );

int main()
{
    int m, n, t;

    scanf("%d %d %d", &m, &n, &t);
    printf("fib(%d) = %d\n", t, fib(t));
    PrintFN(m, n);

    return 0;
}

/* 你的代码将被嵌在这里 */

//套用函数+计数检测解法
int fib( int n )
{
    if (n==1 || n==2)
        return 1;
    return fib(n-1)+fib(n-2);
}
void PrintFN( int m, int n )
{
    int i, count=0;
    for (i=1; i<=20; i++)
    {
        int f=fib(i);
        if (f>=m && f<=n)
        {
            if (count==0)
            {
                printf("%d", f);
                count++;
            }
            else
            {
                printf(" %d", f);
                count++;
            }
        }
    }
    if (count==0)
        printf("No Fibonacci number");
}

//暴力解法1
/*
int fib( int n )
{
    int a[22];
    a[1] = 1;
    a[2] = 1;
    if (n == 1 || n == 2)
        a[n] = 1;
    for (int i = 3; i <= n; i++)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}

void PrintFN( int m, int n )
{
    int flag = 0;
    int a[22000], b[220];
    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= 22000; i++)
    a[i] = a[i - 1] + a[i - 2];
    int k = 0;
    for (m; m <= n; m++)
    {
        for (int i = 1; i <= 22; i++)
        {
            if (m == a[i])
            {
                flag = 1;
                k++;
                b[k] = m;
            }
        }
    }
    for (int i = 1; i <= k; i++)
    {
        if (i == k)
            printf("%d", b[i]);
        else
            printf("%d ", b[i]);
    }
    if (flag == 0)
        printf("No Fibonacci number");
*/