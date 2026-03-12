#include <stdio.h>

double fn( double x, int n );

int main()
{
    double x;
    int n;

    scanf("%lf %d", &x, &n);
    printf("%.2f\n", fn(x,n));

    return 0;
}

/* 你的代码将被嵌在这里 */

double fn( double x, int n )
{
    double item = pow(-1, n-1) * pow(x, n);
    if (x==0)
        return 0;
    if (n==0)
        return 0;
    return item + fn(x, n-1);
}