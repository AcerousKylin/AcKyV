//给定一个十进制正整数n，写下从1到n的所有整数
//然后数一下其中出现的数字“1”的个数
#include<stdio.h>
int main(void)
{
    int n, i=1, bit=1, count=0, number;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        number = i;
        do
        {
            bit = number % 10;
            if (bit==1)
                count++;
            if (number==0)
                break;
        }while(number /= 10);
    }
    printf("%d", count);
    return 0;
}

//同时输入多组数据n
#include<stdio.h>
int main(void)
{
    int n, i=1, bit=1, count=0, number;
    while (~scanf("%d", &n))
    {
        for (i=1; i<=n; i++)
        {
            number = i;
            do
            {
                bit = number % 10;
                if (bit==1)
                    count++;
                if (number==0)
                    break;
            }while(number /= 10);
        }
        printf("%d\n", count);
        count = 0;
    }
    return 0;
}