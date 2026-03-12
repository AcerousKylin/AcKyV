#include<stdio.h>
int main(void)
{
    double r1, r2, r;
    scanf("%lf %lf", &r1, &r2);
    r = 1 / (1 / r1 + 1 / r2);
    printf("%f", r);
    return 0;
}