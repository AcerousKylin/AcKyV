#include<stdio.h>
#include<math.h>
int IsPrime( int n )
{
    int i;
    for (i=2; i<(int)sqrt(n); i++)
    {
        if (n%i==0)
            return 0;
    }
    return 1;
}
int main(void)
{
    int n, i, j=0, count=0;
    scanf("%d", &n);
    int primes[10000];
    for (i=0; i<=n; i++)
        if (IsPrime(i))
            primes[j++] = i;
    for (i=0; i+1<j; i++)
    {
        if (primes[i+1]-primes[i]==2)
            count++;
    }
    printf("%d", count);
    return 0;
}