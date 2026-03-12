//e的近似值=1+1/1!+1/2!+1/3!+……+1/n!
//直到1/n!< 1/1000000 为止（最后一项小于）
#include<stdio.h>
#define min 1e-6
int main(void)
{
    double sum=1.0, item=1.0, i=1;
    while (item>=min)
    {
        item *= 1.0/i;
        sum += item;
        i++;
    }
    printf("%.5lf", sum);
    return 0;
}