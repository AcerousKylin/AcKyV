// 7-10 N分之一序列前n项和
#include<stdio.h>
int main(void)
{
    int n, i;
    double sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        sum += 1.0/i;
    printf("sum = %.6lf", sum);
    return 0;
}

// 7-11 奇数分之一序列前N项和
#include<stdio.h>
int main(void)
{
    int n, i;
    double sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        sum += 1.0/(2*i-1);
    printf("sum = %.6lf", sum);
    return 0;
}

// 7-12 交错序列前N项和1
#include<stdio.h>
int main(void)
{
    int n, i;
    double sum=0, symbol=1.0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        sum += symbol/(3*i+1);
        symbol *= -1.0;
    }
    printf("sum = %.3lf", sum);
    return 0;
}

// 7-18 交错序列前N项和2
#include<stdio.h>
int main(void)
{
    int n, i;
    double sum=0, symbol=1.0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        sum += symbol*i/(2*i-1);
        symbol *= -1.0;
    }
    printf("%.3lf", sum);
    return 0;
}

// 7-19 平方根序列前N项和
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i;
    double sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        sum += sqrt(i);
    printf("sum = %.2lf", sum);
    return 0;
}

// 7-20 求阶乘序列前N项和
#include<stdio.h>
double fact( int n )
{
    if (n==1 || n==0)
        return 1;
    return n * fact(n-1);
}
int main(void)
{
    int n, i, sum=0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
        sum += fact(i);
    printf("sum = %d", sum);
    return 0;
}