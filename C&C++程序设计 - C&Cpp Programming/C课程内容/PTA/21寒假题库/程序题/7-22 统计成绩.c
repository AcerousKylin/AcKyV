#include<stdio.h>
int main(void)
{
    int n, i, count=0;
    double sum=0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        double temp;
        scanf("%lf", &temp);
        sum += temp;
        if (temp>=60)
            count++;
    }
    if (n!=0)
        printf("average = %.1f\n", sum/n);
    else
        printf("average = 0.0\n");
    printf("count = %d", count);
    return 0;
}