#include<stdio.h>
#include<math.h>
int main(void)
{
    /*float i, m, y, r;
    scanf("%f %f %f", &m, &y, &r);
    i = m*pow((1+r),y)-m;
    printf("interest = %.2f",i);
    return 0;*/
    double i, m, y, r;
    scanf("%lf %lf %lf", &m, &y, &r);
    i = m*pow((1+r),y)-m;
    printf("interest = %.2lf", i);
    return 0;
}
