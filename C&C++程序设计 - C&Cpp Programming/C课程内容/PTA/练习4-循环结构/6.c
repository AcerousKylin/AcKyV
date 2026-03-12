//序列 1-2/3+3/5-4/7+5/9-6/11+... 的前N项之和
#include<stdio.h>
int main(void)
{
    int i, n;
    double o, sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        o = i;
        if (i%2==1)
            sum += o/(2*o-1);
        else if (i%2==0)
            sum += -o/(2*o-1);
        else printf("Error!");
    }
    printf("%.3lf", sum);
    return 0;
}