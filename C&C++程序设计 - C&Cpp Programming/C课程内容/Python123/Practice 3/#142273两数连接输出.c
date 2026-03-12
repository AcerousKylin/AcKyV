#include<stdio.h>
int main(void)
{
    int a, b, sum;
    scanf("%d %d", &a, &b);
    if (b>=0&&b<10)
        sum = a*10+b;
    if (b>=10&&b<100)
        sum = a*100+b;
    if (b>=100&&b<1000)
        sum = a*1000+b;
    if (b>=1000)
        sum = a*10000+b;
    printf("%d", sum);
    return 0;
}