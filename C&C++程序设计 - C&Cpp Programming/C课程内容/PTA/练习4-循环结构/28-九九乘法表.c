//对任意给定的一位正整数N，输出从1*1到N*N的部分口诀表
#include<stdio.h>
int main(void)
{
    int n, i, o, fwd, bwd, result;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        for (o=1; o<=i; o++)
        {
            fwd = o;
            bwd = i;
            result = fwd * bwd;
            printf("%d*%d=%-4d", fwd, bwd, result);
            if (fwd==bwd)
                putchar('\n');
            fwd = 0;
        }
    }
    return 0;
}

//1-9全输出简化版
#include<stdio.h>
int main(void)
{
    int i, o;
    for (i=1; i<=9; i++)
    {
        for (o=1; o<=i; o++)
            printf("%d*%d=%d\t", o, i, o*i);
        putchar('\n');
    }
    return 0;
}