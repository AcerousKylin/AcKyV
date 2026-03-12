/*一个四位正整数，满足如下条件：由数字1到数字9组成
各位数字都不相同；从左至右数字降序排列
并且相邻的两个数字前一个不能是后一个的倍数
并且这4位数字不能都是奇数，也不能都是偶数
输入两个4位整数a和b,输出区间[a,b]之间符合条件的所有数*/
#include<stdio.h>
int main(void)
{
    int a, b, number, x1, x2, x3, x4;
    scanf("%d %d", &a, &b);
    for (number=a; number<=b; number++)
    {
        x1=number/1000; x2=(number/100)%10;
        x3=(number/10)%10; x4=number%10;
        if (x1==0 || x2==0 || x3==0 || x4==0)
            continue;
        if (x1==x3 || x1==x4 || x2==x4)
            continue;
        if (! (x1>x2 && x2>x3 && x3>x4))
            continue;
        if (x1%2==0 && x2%2==0 && x3%2==0 && x4%2==0)
            continue;
        if (x1%2==1 && x2%2==1 && x3%2==1 && x4%2==1)
            continue;
        if (x1%x2==0 || x2%x3==0 || x3%x4==0)
            continue;
        printf("%d\n", number);
    }
    return 0;
}