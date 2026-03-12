#include<stdio.h>
#include<math.h>
int main(void)
{
    double x, y;
    scanf("%lf", &x);
    if (x>=0)
        y = sqrt(x);
    if (x<0)
        y = pow(x+1, 2) + 2*x + 1.0/x;
    printf("f(%.2lf) = %.2lf", x, y);
    return 0;
}