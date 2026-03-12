#include <stdio.h>
#include <math.h>

double Cube(double x);

void Star(double *x, double *y, double a, double t);

int main()
{
    double a, t, x, y;
    scanf("%lg%lg", &a, &t);
    Star(&x, &y, a, t);
    printf("%f %f\n", x, y);
    return 0;
}

double Cube(double x)
{
    ...(略)...
}

/* 你提交的代码将被嵌在这里 */

void Star(double *x, double *y, double a, double t)
{
    *x = a * Cube(cos(t));
    *y = a * Cube(sin(t));
}