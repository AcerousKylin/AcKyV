//3n-2的倒数前n项和
#include<stdio.h>
int main(void)
{
    int n, i;
    double fx, fx1;
    fx = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        double count = 3*i+1;
        if (i%2==0) fx1 = 1/count;
        else fx1 = -1/count;
        fx = fx + fx1;
    }
    printf("sum = %.3lf", fx);
    return 0;
}
