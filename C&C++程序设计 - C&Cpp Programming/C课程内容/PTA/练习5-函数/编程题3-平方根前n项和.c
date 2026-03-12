#include<stdio.h>
#include<math.h>
int main(void)
{
    double item, sum=0, n, i;
    scanf("%lf", &n);
    for (i=1; i<=n; i++)
    {
        item = sqrt(i);
        sum += item;
    }
    printf("sum = %.2f", sum);
    return 0;
}