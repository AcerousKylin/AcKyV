//温度转换函数版
#include <stdio.h>
double tempConvert( double c )
{
    double f;
    f = 1.8 * c + 32;
    return f;
}
int main(void)
{
    double c, f;
    scanf("%lf", &c);
    f = tempConvert(c);
    printf("F=%.2f", f);
    return 0;
}