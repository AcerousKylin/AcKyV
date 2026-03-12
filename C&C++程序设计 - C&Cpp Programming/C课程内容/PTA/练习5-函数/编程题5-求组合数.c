#include <stdio.h>
double fact( int n )
{
    if (n==1||n==0)
        return 1;
    return n * fact(n-1);
}
int main(void)
{    
    int m, n;
    double result; 
    scanf("%d%d", &m, &n);
    if(m > 0 && n > 0 && m <= n)
    {
        result = fact(n)/fact(n-m)/fact(m);
        printf("result = %.0f", result);    
    }
    return 0;
}