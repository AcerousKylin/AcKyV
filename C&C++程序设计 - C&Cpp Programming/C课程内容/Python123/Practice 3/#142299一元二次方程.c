#include<stdio.h>
#include<math.h>
int main(void)
{
    double a, b, c, delta, x1, x2;
    scanf("%lf %lf %lf", &a, &b, &c);
    if (a==0&&b!=0&&c!=0)
    {
        x1 = -c / b;
        printf("x=%.2lf", x1);
        return 0;
    }
    else if (a==0&&b==0&&c!=0)
    {
        printf("No solution");
        return 0;
    }
    else if (a==0&&b==0&&c==0)
    {
        printf("Infinitely solution");
        return 0;
    }
    else;
    delta = b*b - 4*a*c;
    if (delta>0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("x1=%.2lf;x2=%.2lf", x1, x2);
        return 0;
    }
    else if (delta==0)
    {

        x1 = -b / 2 * a;
        printf("x1=x2=%.2lf", x1);
        return 0;
    }
    else
    {
        printf("Imaginary root");
        return 0;
    }
}
/*
#include <stdio.h>
#include <math.h>
#define EPSILON 1e-6d
int main(void)
{
    double a, b, c;
    double delta, real_part, imaginary_part;
   	scanf("%lf %lf %lf", &a, &b, &c);
    if(fabs(a) <= EPSILON && fabs(b) <= EPSILON && fabs(c) <= EPSILON)  //a,b,c均为0,无限解
        printf("Infinitely solution\n");
    else if(fabs(a) <= EPSILON && fabs(b) <= EPSILON)   //仅a,b为0,无解
        printf("No solution\n");
    else if(fabs(a) <= EPSILON)    //仅a为0,单根
        printf("x=%.2f\n", -c / b);
    else
    {
        real_part = -b / (2 * a);  //若为虚根,真部为此值
        delta = b * b - 4 * a * c; //判别式Δ
        imaginary_part = sqrt(fabs(delta)) / (2 * a);   //若为虚根,虚部为此值
        if(fabs(delta) <= EPSILON) //Δ=0,两同根
            printf("x1=x2=%.2f\n", real_part);
        else if(delta > EPSILON)   //Δ>0,两不同根
            printf("x1=%.2f;x2=%.2f\n", real_part+imaginary_part, real_part-imaginary_part);
        else                       //Δ<0,有虚根
            printf("Imaginary root\n");
    }
    return 0;
}
*/