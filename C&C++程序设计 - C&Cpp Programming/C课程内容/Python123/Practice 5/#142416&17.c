//求出多组两个数m, n反转(倒序数位)后相加的值
//数据保证int范围，当m和n同时为0时表示输入结束
#include<stdio.h>
int main(void)
{
    int m, n, number1, number2, sum; //int number取代两个numberx
    while (~scanf("%d %d", &m, &n))
    {
        if (m==0 && n==0)
            break;
        number1 = number2 = 0; //number=0，下个循环替换
        while (m>0)
        {
            number1 = number1 * 10 + m % 10;
            m /= 10;
        } //number = 0; sum = number; 同上
        while (n>0)
        {
            number2 = number2 * 10 + n % 10;
            n /= 10;
        }
        sum = number1 + number2; //sum += number;
        printf("%d\n", sum); //number1 + number2
        sum = 0;
    }
    return 0;
}

//转身乘号可用@表示，2个正整数转身乘法(A@B)的规则是：将被乘数A转身后再乘以乘数B
//此外规定：数字转身时处于末尾的所有连续零不参与转身
//第一行是一个整数N表示有N组数据,接下来N行中，每行两个正整数A和B，代表一组数据，数据和结果保证在int范围之内
//模块版：
#include<stdio.h>
int tx( int i )
{
    int n=0;
    while (i>0)
    {
        n = n * 10 + i % 10;
        i /= 10;
    }
    return n;
}

int savez( int n, int rebmun)
{
    int count=0;
    while (n%10==0)
    {
        count++;
        n /= 10;
    }
    for (; count>0; count--)
        rebmun*=10;
    return rebmun;
}
int main(void)
{
    int n, a, b, number, rebmun, result;
    scanf("%d", &n);
    while (~scanf("%d %d", &a, &b))
    {
        rebmun = savez(a, tx(a));
        result = rebmun * b;
        printf("%d\n", result);
    }
    return 0;
}

//模组版：
/*
#include<stdio.h>
int main(void)
{
    int n, a, b, a1, number=0, count=0, result;
    scanf("%d", &n);
    while(~scanf("%d %d", &a, &b))
    {
        number = result = 0;
        a1 = a;
        while (a>0)
        {
            number = number * 10 + a % 10;
            a /= 10;
        }
        while (a1%10==0)
        {
            count++;
            a1 /= 10;
        }
        for (; count>0; count--)
            number *= 10;
        result = number * b;
        printf("%d\n", result);
    }
    return 0;
}
*/