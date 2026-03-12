#include <stdio.h>

void FindNarc(int lower, int upper);

int main()
{
    int min, max;
    scanf("%d %d", &min, &max);
    FindNarc(min, max);
    putchar('\n');
    return 0;
}

/* 你提交的代码将被嵌在这里 */

#define Cube(x) x*x*x
int IsNarc(int x)
{
    int i, temp=x, result=0;
    while (temp!=0)
    {
        result += Cube(temp%10);
        temp /= 10;
    }
    if (x==0 || x==1 || x!=result)
        return 0;
    if (x==result)
        return 1;
}

// 以上宏函数和IsNarc函数题内已经提供

void FindNarc(int lower, int upper)
{
    int i;
    for (i=lower; i<=upper; i++)
    {
        int flag=IsNarc(i);
        if (flag)
            printf("%d\n", i);
        else
            continue;
    }
}