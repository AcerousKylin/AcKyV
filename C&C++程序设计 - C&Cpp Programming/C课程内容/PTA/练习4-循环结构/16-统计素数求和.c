//统计给定整数M和N区间内素数的个数并对它们求和
#include<stdio.h>
int main(void)
{
    int m, n, amount, count, number, multier, sum;
    scanf("%d %d", &m, &n);
    sum = amount = count = 0;
    for (number=m; number<=n; number++)
    {
        for (multier=1; multier<=number; multier++)
        {
            if (number%multier!=0) count++; // count=因数的数量
        }
        if (number-count==2)
        {
            amount++;
            sum += number;
        }
        /*
        如果[M,N]区间的某个数减去因数数量等于2
        意味着这个数的因数只有1和它自己两个
        而number的值不仅仅是将要测试的每个数
        还恰好是number在被检测时被除的所有multier的数量
        所以只要检测的因数数量count比number值多2个
        就表明该数为质数，amount++。
        */
        count = 0;
    }
    printf("%d %d", amount, sum);
    return 0;
}
