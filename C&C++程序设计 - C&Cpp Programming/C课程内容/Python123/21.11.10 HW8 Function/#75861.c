//求三角形面积函数版
#include <stdio.h>
#include <math.h>
double areaOfTriangle(double a, double b, double c)
{
    double s, p;
    if (a+b<c || b+c<a || a+c<b)
        return 0;
    p = (a + b + c) * 0.5;
    s = sqrt(p*(p-a)*(p-b)*(p-c));
    return s;
}
int main(void)
{
    double a, b, c, s;
    scanf("%lf,%lf,%lf", &a, &b, &c);
    s = areaOfTriangle(a, b, c);
    if (s==0)
        printf("不能构成三角形");
    else
        printf("area=%.2f", s);
    return 0;
}