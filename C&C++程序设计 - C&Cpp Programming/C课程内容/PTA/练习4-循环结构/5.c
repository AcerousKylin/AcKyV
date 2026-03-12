//序列 2/1+3/2+5/3+8/5+... 的前n项之和
#include<stdio.h>
int main(void)
{
    int i, n;
    double s1, sn=0;
    double n0, d0, n1, d1;
    scanf("%d", &n);
    n0 = 1; d0 = 1;
    for (i=1; i<=n; i++)
    {
        n1 = n0+d0;
        d1 = n0;
        sn = sn + n1/d1;
        n0 = n1;
        d0 = d1;
    }
    printf("%.2lf", sn);
    return 0;
}