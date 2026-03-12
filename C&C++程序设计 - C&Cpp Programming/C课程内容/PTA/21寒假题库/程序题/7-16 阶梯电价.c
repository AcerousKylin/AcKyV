#include<stdio.h>
int main(void)
{
    int degree;
    scanf("%d", &degree);
    if (degree<0)
        printf("Invalid Value!");
    if (degree>=0 && degree<=50)
        printf("cost = %.2f", 0.53*degree);
    if (degree>50)
    {
        double cost;
        cost = 50 * 0.53 + (degree - 50) * 0.58;
        printf("cost = %.2f", cost);
    }
    return 0;
}