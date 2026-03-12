//编程输入正整数a(10000>=a>=2)，输出不小于a的第一对孪生素数
//差是2的两个素数被称为孪生素数
//函数版
#include<stdio.h>
int IsPrime( int n )
{
    int i;
    for (i=2; i<n; i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int n, i, count=0;
    scanf("%d", &n);
    for (i=n;; i++)
    {
        if (IsPrime(i)==1&&IsPrime(i+2)==1)
        {
            printf("%d %d", i, i+2);
            break;
        }
    }
    return 0;
}