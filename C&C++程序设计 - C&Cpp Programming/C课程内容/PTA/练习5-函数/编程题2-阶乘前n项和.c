#include<stdio.h>
int factorial(n)
{
    if (n==0 || n==1)
        return 1;
    return n * factorial(n-1);
}

int main(void)
{
    int i, n, sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        sum += factorial(i);
    printf("%d", sum);
    return 0;
}