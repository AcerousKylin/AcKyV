#include<stdio.h>
int main(void)
{
    int a, b, c, d, judgem, sum=0;
    judgem = scanf("%d", &a);
    if (judgem==1)
        sum += a;
    judgem = scanf("%d", &b);
    if (judgem==1)
        sum += b;
    judgem = scanf("%d", &c);
    if (judgem==1)
        sum += c;
    judgem = scanf("%d", &d);
    if (judgem==1)
        sum += d;
    printf("%d", sum);
    return 0;
}