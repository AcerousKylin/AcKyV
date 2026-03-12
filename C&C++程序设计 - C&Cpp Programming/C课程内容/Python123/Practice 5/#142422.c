//输入一个正整数N（long long型范围内）
//输出N的奇半数和偶半数。N的奇半数就是N的奇数位组成的数，N的偶半数就是N的偶数位组成的数
//从右侧开始数
#include<stdio.h>
int main(void)
{
    long long n, i=0, odd=0, even=0; long long b[20];
    scanf("%lld", &n);
    for (i=1; n>0 || n%10!=0; i++)
    {
        b[i] = n % 10;
        n /= 10;
    }
    for (; i>=1; i--)
    {
        if (i%2==1)
            odd = b[i]+odd*10;
        else if (i%2==0)
            even = b[i]+even*10;
    }
    printf("%d %d", odd, even);
    return 0;
}