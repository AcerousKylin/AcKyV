//输入任意一个正整数，如果它是奇数，则对它乘3再加1
//如果它是偶数，则对它除以2，如此循环，最终都能够得到1
//输出其运算过程的每一个数（奇偶归一猜想）
#include<stdio.h>
int main(void)
{
    int n, i;
    scanf("%d", &n);
    for(i=1; n>1; i++)
    {
        n = (n%2==0)?n/2:3*n+1;
        if (i!=1)
            printf(" ");
        printf("%d", n);
    }
    return 0;
}

//输入区间，输出多组数据
#include<stdio.h>
int main(void)
{
    int a, b, i, j, n;
    scanf("%d %d", &a, &b);
    for (j=a; j<=b; j++)
    {
        printf("%d:", j);
        n = j;
        for (i=1; n>1; i++)
        {
            n = (n%2==0)?n/2:3*n+1;
            if (i!=1)
                printf(" ");
            printf("%d", n);
        }
        printf("\n");
    }
    return 0;
}