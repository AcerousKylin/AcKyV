//对输入的一个整数，从高位开始逐位分割并输出它的各位数字
#include<stdio.h>
#include<math.h>
int main(void)
{
    long n, i, bit, o, bits;
    scanf("%ld", &n);
    for (i=10; i>=0; i--)
    {
        bit = n / pow(10, i);
        if (bit!=0)
        {
            for (o=i; o>=0; o--)
            {
                bits = n / pow(10, o);
                printf("%d ", bits);
                n -= bits*pow(10, o);
            }
            return 0;
        }
        else if (n==0)
        {
            printf("0 ");
            return 0;
        }
        else continue;
    }
}