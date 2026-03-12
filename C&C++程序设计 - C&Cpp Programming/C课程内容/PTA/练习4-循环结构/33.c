/*水仙花数是指一个N位正整数（N≥3），它的每个位上的数字的N次幂之和等于它本身
例如：153=1^3+5^3+3^3,计算所有N位水仙花数*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i;
    long number1, number, sum=0, upr, lwr;
    double bits;
    scanf("%d", &n);
    upr = pow(10,n); lwr = pow(10,n-1); 
    for (number=lwr; number<upr; number++)
    {
        number1 = number;
        for (i=1; i<=n; i++)
        {
            bits = number1 % 10;
            sum += pow(bits, n);
            number1 /= 10;
        }
        if (sum==number)
            printf("%ld\n", number);
        sum = 0;
    }
    return 0;
}
//7位的水仙花数有：1741725、4210818、9800817、9926315