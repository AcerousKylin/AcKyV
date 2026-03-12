//n的平方和倒数和的前n项和
#include<stdio.h>
#include<math.h>
int main(void)
{
    int m, n;
    double i, sum;
    scanf("%d %d", &m, &n);
    for (m; m<=n; m++)
    {
        i = m;
        sum += i*i+1/i;
    }
    printf("sum = %lf", sum);
    return 0;
}