// 斐波那契数列，输入第n项
#include<stdio.h>
int main(void)
{
    int f[3], i, n;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        if (i==1)
        {
            f[1] = 1;
            f[2] = f[1];
        }
        if (i>1)
        {
            f[3] = f[1] + f[2];
            f[1] = f[2];
            f[2] = f[3];
        }
        if (i!=n)
            printf("%d,", f[3]);
        if (i==n)
            printf("%d", f[3]);
    }
    return 0;
}

//精简版
#include<stdio.h>
int main(void)
{
    int i, f1, f2, f3, n;
    f1 = 1; f2 = 1;
    scanf("%d", &n);
    printf("1,1");
    for (i=3; i<=n; i++)
    {
            f3 = f1 + f2;
            printf(",%d", f3);
            f1 = f2; f2 = f3;
    }
    return 0;
}