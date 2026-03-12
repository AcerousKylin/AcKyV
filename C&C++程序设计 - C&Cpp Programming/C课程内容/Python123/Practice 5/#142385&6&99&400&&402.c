//输入若干整数（至少一个），输出累和
#include<stdio.h>
int main(void)
{
    int n, sum=0;
    while (~scanf("%d", &n))
    {
        sum += n;
    }
    printf("%d", sum);
    return 0;
}

//输入若干整数最少一个，绝对值不超过10000），输出最大值
#include<stdio.h>
int main (void)
{
    int n, max;
    scanf("%d", &max);
    while (~scanf("%d", &n))
    {
        if (n>max)
            max = n;
    }
    printf("%d", max);
    return 0;
}

//输入若干数对，输出每对数的和
#include<stdio.h>
int main(void)
{
    int a, b, sum;
    while (~scanf("%d %d", &a, &b))
    {
        sum = a + b;
        printf("%d\n", a+b);
    }
    return 0;
}

//输入若干组数据，每组有3个整数，表示一个加法算式
//输出正确的算式数量
#include<stdio.h>
int main(void)
{
    int a, b, c, count;
    while(~scanf("%d %d %d", &a, &b, &c))
    {
        if (a+b==c)
            count++;
    }
    printf("%d", count);
    return 0;
}

/*2021年日本东京奥运会，A国的运动员参与了n天的决赛项目(1≤n≤17)
输入n+1行，第1行是参加决赛项目的天数
其后n行，每一行是某天获得的金银铜牌数目，空格分开
输出A国的金银铜牌总数和总奖牌数，空格分开*/
#include<stdio.h>
int main(void)
{
    int n, g, s, b, ag=0, as=0, ab=0, a;
    scanf("%d", &n);
    while (~scanf("%d %d %d", &g, &s, &b))
    {
        ag += g; as += s; ab += b;
    }
    a = ag + as + ab;
    printf("%d %d %d %d", ag, as, ab, a);
    return 0;
}