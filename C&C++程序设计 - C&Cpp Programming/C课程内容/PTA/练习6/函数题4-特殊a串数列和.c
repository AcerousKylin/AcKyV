#include <stdio.h>

int fn( int a, int n );
int SumA( int a, int n );

int main()
{
    int a, n;

    scanf("%d %d", &a, &n);
    printf("fn(%d, %d) = %d\n", a, n, fn(a,n));        
    printf("s = %d\n", SumA(a,n));    

    return 0;
}

/* 你的代码将被嵌在这里 */

int fn( int a, int n )
{
    if (n==1)
        return a;
    return a + 10*fn(a, n-1);
}

int SumA( int a, int n )
{
    int i, sum;
    for (i=1; i<=n; i++)
        sum += fn(a, i);
    return sum;
}