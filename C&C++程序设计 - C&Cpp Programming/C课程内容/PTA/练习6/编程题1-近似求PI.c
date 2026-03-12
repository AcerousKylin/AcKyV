#include<stdio.h>
double numerator( int i )
{
    if (i==0)
        return 1;
    return i * numerator(i-1);
}

double denominator( int i )
{
    if (i==0)
        return 1;
    return (2*i+1) * denominator(i-1);
}

int main(void)
{
    int i; double n[25], d[25];
    double eps, item=114514, pi=0;
    scanf("%le", &eps);
    for (i=0; i<25; i++)
    {
        n[i] = numerator(i);
        d[i] = denominator(i);
    }
    for (i=0; item>=eps; i++)
    {
        item = n[i] / d[i];
        pi += item;
    }
    printf("PI = %.5f", pi+pi);
    return 0;
}