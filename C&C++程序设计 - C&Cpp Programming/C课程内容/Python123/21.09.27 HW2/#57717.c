#include <stdio.h>
#include <math.h>
int main(void)
{
    float a,b,c,s;
    scanf("%f,%f,%f",&a,&b,&c);
    s=(a+b+c)/2;
    printf("area=%.2f",sqrt(s*(s-a)*(s-b)*(s-c)));
    return 0;
}