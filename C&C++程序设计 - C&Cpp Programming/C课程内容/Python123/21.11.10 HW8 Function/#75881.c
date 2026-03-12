//求圆的面积函数版
#include <stdio.h>
#define pi 3.14
double areaOfCircle(double r)
{
    double s;
    s = pi*r*r;
    return s;
}
int main(void)
{
    double r, s;
    scanf("%lf", &r);
    s = areaOfCircle(r);
    printf("area=%.2lf", s);
    return 0;
}