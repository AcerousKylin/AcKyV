//递归实现辗转相除法求最大公约数
//辗转相除：(a,b)->(a,ka+c)->(a,c)->(kc+b,c)->...
#include<stdio.h>
int gcd(int a, int b)
{
    int t;
    if (a<b) //为了方便设置出口，固定a、b的运算顺序
    {
        t = b;
        b = a;
        a = t;
    }
    if (a%b==0) //判断最大公约数
        return b;
    return gcd(a%b, b); //递归余数和不能作为公约数的值
}
int main(void)
{
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d", gcd(a, b));
    return 0;
}