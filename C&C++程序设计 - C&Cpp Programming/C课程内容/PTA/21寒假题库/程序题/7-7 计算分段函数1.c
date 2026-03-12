#include<stdio.h>
int main(void)
{
    double x, y;
    scanf("%lf", &x);
    if (x!=0)
        y = 1.0 / x;
    if (x==0)
        y = 0;
    printf("f(%.1lf) = %.1lf", x, y);
    return 0;
}