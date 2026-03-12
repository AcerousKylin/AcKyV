//求输入数列中的奇数和
#include<stdio.h>
int main(void)
{
    int n, i, sum=0;
    do
    {
        scanf("%d", &n);
        if (n%2==1)
            sum += n;
        else;
    } while (n>0);
    printf("%d", sum);
    return 0;
}