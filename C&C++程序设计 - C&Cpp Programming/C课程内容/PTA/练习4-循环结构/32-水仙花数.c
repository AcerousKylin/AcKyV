/*所谓完数就是该数恰好等于除自身外的因子之和
例如：6=1+2+3，其中1、2、3为6的因子
找出任意两正整数m和n之间的所有完数*/
#include<stdio.h>
int main(void)
{
    int m, n, multier, number, sum, judgem=0;
    scanf("%d %d", &m, &n);
    for (number=m; number<=n; number++)
    {
        sum = 1;
        if (number==1) continue;
        for (multier=2; multier<number; multier++)
        {
            if (number%multier==0)
                sum += multier;
        }
        if (sum==number)
        {
            printf("%d = 1", number);
            for (multier=2; multier<number; multier++)
            {
                if (number%multier==0)
                    printf(" + %d", multier);
            }
            printf("\n");
            judgem = 1; //利用改变变量的值来进行判断
        }
    }
    if (judgem==0) printf("None");
    return 0;
}