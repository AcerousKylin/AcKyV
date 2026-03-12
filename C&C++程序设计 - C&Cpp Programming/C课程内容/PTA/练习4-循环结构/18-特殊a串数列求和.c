//数字a到n个a累加
#include<stdio.h>
#include<math.h>
int main(void)
{
    int n, i, a;
    double mid=0, s=0;
    scanf("%d %d", &a, &n);
    for (i=0; i<n; i++)
    {
        mid += pow(10, i)*a;
        s += mid;
    }
    printf("s = %.0lf", s);
    return 0;
}