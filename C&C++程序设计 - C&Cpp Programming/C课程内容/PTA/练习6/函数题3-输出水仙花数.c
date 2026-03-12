#include <stdio.h>

int narcissistic( int number );
void PrintN( int m, int n );

int main()
{
    int m, n;

    scanf("%d %d", &m, &n);
    if ( narcissistic(m) ) printf("%d is a narcissistic number\n", m);
    PrintN(m, n);
    if ( narcissistic(n) ) printf("%d is a narcissistic number\n", n);

    return 0;
}

/* 你的代码将被嵌在这里 */

int narcissistic( int number )
{
    int n[3]; int *pn; int n_=number, sum;
    for (pn=n; pn<n+3; pn++)
    {
        *pn = n_ % 10;
        n_ /= 10;
    }
    for (pn=n; pn<n+3; pn++)
        sum += pow(*pn, 3);
    if (number==sum)
        return 1;
    else
        return 0;
}