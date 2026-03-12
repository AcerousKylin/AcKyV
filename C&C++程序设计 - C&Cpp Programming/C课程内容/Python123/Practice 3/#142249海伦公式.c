#include<stdio.h>
int main(void)
{
    double a, b, c, p, s;
    scanf("%lf %lf %lf", &a, &b, &c);
    p = (a + b + c) / 3;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    printf("%f", s);
    return 0;
}