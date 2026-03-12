#include <stdio.h>
#include <math.h>

double funcos( double e, double x );

int main()
{    
    double e, x;

    scanf("%lf %lf", &e, &x);
    printf("cos(%.2f) = %.6f\n", x, funcos(e, x));

    return 0;
}

/* 你的代码将被嵌在这里 */

double fact( int n )
{
    if (n==1||n==0)
        return 1;
    return n * fact(n-1);
}
double funcos( double e, double x )
{
    double item=1, sum=0, n=0, p=0;
    while(fabs(item)>=e)
    {
        item = pow(-1, p) * pow(x, n) / fact(n);
        sum += item;
        p += 1; n += 2;
    }
    return sum;
}