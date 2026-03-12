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

int IntPower( int n, int number)
{
    if (n==1)
        return number;
    return number*IntPower(n-1, number);
}

int narcissistic( int number )
{
    int i, temp=number, result=0, bit=0;
    while (temp!=0)
    {
        bit++;
        temp /= 10;
    }
    temp = number;
    while (temp!=0)
    {
        result += IntPower(bit, temp%10);
        temp /= 10;
    }
    if (number==0 || number==1 || number!=result)
        return 0;
    if (number==result)
        return 1;
}

void PrintN( int m, int n )
{
    int i;
    for (i=m+1; i<n; i++)
        if (narcissistic(i))
            printf("%d\n", i);
}