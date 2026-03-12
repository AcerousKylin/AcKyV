#include<stdio.h>
#include<math.h>
int main(void)
{
    float a, b, c, x, y;
    scanf("%f,%f,%f", &a, &b, &c);
    x = -b/2/a;
    y = sqrt(b*b-4*a*c)/2/a;
    printf("x1=%.2f\n", x+y);
    printf("x2=%.2f"  , x-y);
    return 0;
}
