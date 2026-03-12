//#142403
/*输入两个整数
对于两数闭区间内的所有整数依次输出其真约数
输出：某数字: 其真约数（用空格隔开）
      ...*/
#include <stdio.h>
int main(void)
{
    int a, b, number, i;
    scanf("%d %d", &a, &b);
    for (number=a; number<=b; number++)
    {
        printf("%d:1", number);
        for (i=2; i<number; i++)
        {
            if (number%i==0)
                printf(" %d", i);
            if (i==number-1)
                printf("\n");
        }
    }
    return 0;
}

//#142404
//输入两整数，输出其闭区间内所有的素数（一定会有）
//用逗号分割输出结果
#include<stdio.h>
int main(void)
{
    int a, b, number, i, count=0, amount=0;
    scanf("%d %d", &a, &b);
    for (number=a; number<=b; number++)
    {
        for(i=2; i<number; i++)
        {
            if (number%i==0)
                break;
            count++;
        }
        if (number-count==2)
        {
            amount++;
            if (amount==1)
                printf("%d", number);
            if (amount>1)
                printf(",%d", number);
        }
        count = 0;
    }
    return 0;
}

//#142407
//有两个整数a,b(2<=a<b)，输出整数区间[a，b]内的所有素数。‪‬‪‬‪‬‪‬‪‬‮‬‭‬‪‬‪‬‪‬‪‬‪‬‪‬‮‬‪‬‪‬‪‬‪‬‪‬‪‬‪‬‮‬‫‬‪‬‪‬‪‬‪‬‪‬‪‬‮‬‫‬‫‬‪‬‪‬‪‬‪‬‪‬‮‬‪‬‪‬‪‬‪‬‪‬‪‬‪‬‮‬‫‬‪‬
//一次性输入多行两组数据，一次性输出多行输出
//ver.强行输出（适用直接单次多行输入）
#include<stdio.h>
int main(void)
{
    int a, b, number, i, count=0, amount=0;
    while (~scanf("%d %d", &a, &b))
    {
        for (number=a; number<=b; number++)
        {
            for(i=2; i<number; i++)
            {
                if (number%i==0)
                    break;
                count++;
            }
            if (number-count==2)
            {
                amount++;
                if (amount==1)
                    printf("%d", number);
                if (amount>1)
                    printf(",%d", number);
            }
            count = 0;
        }
        printf("\n");
        amount = 0;
    }
    return 0;
}

//ver.多维数组版本（未通过）
#include<stdio.h>
int main(void)
{
    int l=1, c=1; int r[3][15]; int q[3]={1,1,1};
    int a, b, number, i, count=0, amount=0;
    while (~scanf("%d %d", &a, &b))
    {
        for (number=a; number<=b; number++)
        {
            for(i=2; i<number; i++)
            {
                if (number%i==0)
                    break;
                count++;
            }
            if (number-count==2)
            {
                r[l][q[l]] = number;
                q[l]++;
            }
            count = 0;
        }
        l++;
        
    }
    int j, k;
    for (k=1; k<=l; k++)
    {
        for (j=1; j<=q[k]; j++)
        {
            if (j<q[k])
                printf("%d,", r[k][j]);
            if (j==q[k])
                printf("%d\n", r[k][j]);
        }
    }
    return 0;
}