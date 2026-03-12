#include<stdio.h>
int main(void)
{
    int price, time; float laxury;
    scanf("%d %d", &price, &time);
    laxury = price*time*(1-0.15);
    printf("%.2f", laxury);
    return 0;
}