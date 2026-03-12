#include<stdio.h>
#include<math.h>

double dist( double x1, double y1, double x2, double y2)
{
    return sqrt( pow(x1-x2, 2) + pow(y1-y2, 2));
}

int main(void)
{
    double x1, x2, x3, y1, y2, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    
    if((y2-y1)/(x2-x1)==(y3-y1)/(x3-x1))
    {
        printf("Impossible");
        exit(0);
    }

    double s12, s13, s23, l, p, a;
    s12 = dist(x1, y1, x2, y2);
    s13 = dist(x1, y1, x3, y3);
    s23 = dist(x2, y2, x3, y3);
    l = s12 + s13 + s23;
    p = (s12 + s13 + s23) / 2;
    a = sqrt(p*(p-s12)*(p-s13)*(p-s23));
    printf("L = %.2f, A = %.2f", l, a);
    return 0;
}