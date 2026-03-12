#include<stdio.h>
int main(void)
{
    int n, i;
    double fx, fx1;
    fx = 0;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        double count = i;
        fx1 = 1/count;
        fx = fx + fx1;
    }
    printf("sum = %lf", fx);
    return 0;
}