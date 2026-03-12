/*形如2^n−1的素数称为梅森数
对任一正整数n（n<20），输出所有不超过2^n−1的梅森数*/
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i, number, multier, count;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        number = pow(2, i)-1;
        for (multier=1; multier<=number; multier++)
        {
            if (number%multier!=0)
                count++;
        }
        if (number-count==2)
            printf("%d\n", number);
        if (n==1)
            printf("None");
        count = 0;
    }
    return 0;
}