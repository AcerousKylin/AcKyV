//奇数的倒数前n项和
#include<stdio.h>
int main(void)
{
    int n, i;
    double fx, fx1;
    fx = 0;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        double count = 2*i+1;
        fx1 = 1/count;
        fx = fx + fx1;
    }
    printf("sum = %lf", fx);
    return 0;
}
