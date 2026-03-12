//判断素数函数制表版
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
    for (i=2; i<=n; i++)
    {
        if (IsPrime(i)==1)
        {
            count++;
            printf("%d\t", i);
            if (count==5)
            {
                printf("\n");
                count = 0;
            }
        }
    }
    return 0;
}