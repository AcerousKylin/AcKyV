#include<stdio.h>
int digit(int n, int f)
{
    int sum;
    if (n==0)
        digit(0, f) = 0;
    else
    {
        sum += digit(n,f);
        if (n + sum == f)
            return n;
        else
            return n % 10 + digit(n/10, f);
    }
}
int digit_n(int f)
{
    int n
    if (f-n==digit_n(f-n))
}