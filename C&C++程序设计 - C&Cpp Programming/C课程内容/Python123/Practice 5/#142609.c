//根号2的迭代，公式为x[n]=pow((n[n-1]+2), 0.5)
#include<stdio.h>
int main(void)
{
    double n, i, x0 = 99999999, x1;
    scanf("%lf", &n);
    for (i=1; i<=n; i++)
    {
        x1 = pow(x0+2, 0.5);
        x0 = x1;
    }
    printf("x[%.0lf]=%0.10lf", n, x1);
    return 0;
}