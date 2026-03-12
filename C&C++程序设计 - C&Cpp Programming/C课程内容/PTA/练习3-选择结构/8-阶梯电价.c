#include<stdio.h>
int main(void)
{
    float p, cost;
    scanf("%f", &p);
    if (p>50)
    {
        cost = 50*0.53+(p-50)*0.58;
        printf("cost = %.2f", cost);
    }
    else if (p<0)
    {
        printf("Invalid Value!");
    }
    else
    {
        cost = 0.53*p;
        printf("cost = %.2f", cost);
    }
    return 0;
}
