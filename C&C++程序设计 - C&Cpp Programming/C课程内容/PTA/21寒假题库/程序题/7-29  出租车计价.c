#include<stdio.h>
int main(void)
{
    double dist, time, fee;
    scanf("%lf %lf", &dist, &time);
    if (dist<=3)
        fee = 10;
    if (dist>3 && dist<=10)
        fee = 10 + (dist-3) * 2;
    if (dist>10)
        fee = 24 + (dist-10) * 3;
    if(time>=5)
        fee += 2 * (int)(time / 5);
    if (fee-(int)fee>=0.5)
        fee++;
    printf("%.0lf", fee);
    return 0;
}