#include<stdio.h>
int main(void)
{
    int i, sum=0;
    for (i=0; i<4; i++)
    {
        int temp;
        scanf("%d", &temp);
        sum += temp;
    }
    printf("Sum = %d; Average = %.1f", sum ,sum/4.0);
    return 0;
}