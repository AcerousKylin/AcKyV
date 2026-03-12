#include<stdio.h>
#define P 3.14159265
int main(void)
{
    double r, s, v;
    scanf("%lf", &r);
    s = 4*P*r*r;
    v = 4*P*r*r*r/3;
    printf("%.2lf %.2lf", s, v);
    return 0;
}