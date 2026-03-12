//输入一个非负整数N（long long型范围内）
//输出这个正整数N是几位数
#include<stdio.h>
int main(void)
{
    long long n, bit=0;
    scanf("%lld", &n);
    if (n==0)
    {
        printf("1");
        return 0;
    }
    while (n>0 || n%10!=0)
    {
        bit++;
        n /= 10;
    }
    printf("%d", bit);
    return 0;
}

//输入一个正整数N（long long型范围内）
//输出N中的所有数字的和
#include<stdio.h>
int main(void)
{
    long long n, sum=0;
    scanf("%lld", &n);
    while (n>0 || n%10!=0)
    {
        sum += n%10;
        n /= 10;
    }
    printf("%d", sum);
    return 0;
}

//输入一个正整数N（long long型范围内）
//假设N中的所有数字的和是M，如果M大于9，再求出M的所有数字之和
//重复这个过程，直到数字和为1位数，输出这个终极数字和
#include<stdio.h>
int main(void)
{
    long long n, m=0, m0;
    scanf("%lld", &n);
    while (n>0 || n%10!=0)
    {
        m += n%10;
        n /= 10;
        if (m>9)
        {
            m0 = m; m = 0;
            while (m0>0)
            {
                m += m0 % 10;
                m0 /= 10;
            }
        }
    }
    printf("%d", m);
    return 0;
}