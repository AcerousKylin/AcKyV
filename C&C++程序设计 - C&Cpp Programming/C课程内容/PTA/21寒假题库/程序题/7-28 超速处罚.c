#include<stdio.h>
int main(void)
{
    double speed, limit, percentage;
    scanf("%lf %lf", &speed, &limit);
    percentage = 100.0*(speed/limit-1);
    if (speed>=limit*1.5)
        printf("Exceed %.0lf%%. License Revoked", percentage);
    else if (speed>=limit*1.1)
        printf("Exceed %.0lf%%. Ticket 200", percentage);
    else
        printf("OK");
    return 0;
}