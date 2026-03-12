#include <stdio.h>
#define TOL 1E-3

double dist( double h, double p );

int main()
{
    double h, p, d;
    scanf("%lf %lf", &h, &p);
    d = dist(h, p);
    printf("%.6f\n", d);
    return 0;
}

/* 你的代码将被嵌在这里 */

double dist( double h, double p )
{
    double bounced=h, d=h;
    while(bounced*p>=TOL)
    {
        bounced = bounced * p;
        d += bounced * 2;
    }
    return d;
}
/*
|               h
|
|||             h*p
|||
|||||           h*p*p
|||||
|||||||         h*p*p*p
|||||||||       h*p*p*p*p
|||||||||||     h*p*p*p*p*p
|||||||||||||   h*p*p*p*p*p*p
*/