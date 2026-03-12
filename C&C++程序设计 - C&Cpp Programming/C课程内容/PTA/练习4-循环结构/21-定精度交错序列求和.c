/*计算序列部分和 1 - 1/4 + 1/7 - 1/10 + ... 
直到最后一项的绝对值不大于给定精度eps*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    double s, sum=0, mid, item, i=1;
    scanf("%lf", &s);
    do
    {
        item = 1/(3*i-2);
        mid = pow(-1, i-1)*item;
        sum += mid;
        i++;
    }while (fabs(item)>s);
    printf("sum = %lf", sum);
}