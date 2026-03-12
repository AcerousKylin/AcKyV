//输入精度值，计算e的近似值
#include<stdio.h>
#include<math.h>
int main(void)
{
    double x, sum=1, item=1, i=1;
    scanf("%lf", &x);
    for (i=1; fabs(item)>=x; i++)
    {
        item *= 1/i;
        sum += item;
    }
    printf("%.10lf", sum);
    return 0;
}