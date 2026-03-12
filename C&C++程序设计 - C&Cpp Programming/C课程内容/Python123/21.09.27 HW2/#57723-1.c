#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, c;
    scanf("%f,%f,%f", &a, &b, &c);
    printf("x1=%.2f\n", (-b+sqrt(b*b-4*a*c))/2/a);
    printf("x2=%.2f"  , (-b-sqrt(b*b-4*a*c))/2/a);
    return 0;
}
