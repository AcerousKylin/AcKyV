#include <stdio.h>
#include <math.h>

void Cycloid(double *x, double *y, double a, double t);

int main()
{
    double a, t, x, y;
    scanf("%lg%lg", &a, &t);
    Cycloid(&x, &y, a, t);
    printf("%.10g %.10g\n", x, y);
    return 0;
}

/* 你提交的代码将被嵌在这里 */

void Cycloid(double *x, double *y, double a, double t)
{
    *x = a * (t - sin(t));
    *y = a * (1 - cos(t));
}