/*小明想给自己的银行卡设置一个6位数字的密码，应符合如下规则：
(1)左侧数第1,3,5位数字为奇数
(2)左侧数第2,4,6位数字为偶数
(3)任意两位数字不相同
(4)中间两位不是月份(不在1-12之间)，后两位不是日期(不在1-31之间)
(5)前三位非升序非降序排列，后三位非升序非降序排列
(6) 前三位与后三位之差被23整除余13
输入两个六位数a,b,输出区间[a,b]之间所有符合条件的密码*/
#include<stdio.h>
int main(void)
{
    int a, b, number, x1, x2, x3, x4, x5, x6;
    scanf("%d %d", &a, &b);
    for (number=a; number<=b; number++)
    {
        x1=number/100000; x2=(number/10000)%10;
        x3=(number/1000)%10; x4=(number/100)%10;
        x5=(number/10)%10; x6=(number%10);
        if (! (x1%2==1 && x3%2==1 && x5%2==1))
            continue;
        if (! (x2%2==0 && x4%2==0 && x6%2==0))
            continue;
        if (x1==x2 || x1==x3 || x1==x4 || x1==x5 || x1==x6)
            continue;
        if (x2==x3 || x2==x4 || x2==x5 || x2==x6)
            continue;
        if (x3==x4 || x3==x5 || x3==x6)
            continue;
        if (x4==x5 || x4==x6)
            continue;
        if (x5==x6)
            continue;
        if ((x3*10+x4)>=1 && (x3*10+x4)<=12)
            continue;
        if ((x5*10+x6)>=1 && (x5*10+x6)<=31)
            continue;
        if ((x1>x2 && x2>x3) || (x4>x5 && x5>x6))
            continue;
        if ((x1<x2 && x2<x3) || (x4<x5 && x5<x6))
            continue;
        if (((x1*100+x2*10+x3)-(x4*100+x5*10+x6))%23!=13)
            continue;
        printf("%d\n", number);
    }
    return 0;
}