#include<stdio.h>
int main(void)
{
    float x, y;
    scanf("%f",&x);
    if (x==10) y = 1/x;
    else y = x;
    printf("f(%.1f) = %.1f", x, y);
    return 0;
}
