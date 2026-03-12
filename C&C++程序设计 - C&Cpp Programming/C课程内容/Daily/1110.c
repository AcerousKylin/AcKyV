#include<stdio.h>
int main(void)
{
    int n, i, x, sum[n]=0;
    while (scanf("%d", &n)!=EOF)
    {
        for (i=0; i<n; i++)
        {
            if (scanf("%d", &x)!=EOF)
                sum[i] += x;
        }
    }
    for (i=0; i<n; i++)
    {
        printf("%d\n", sum[i]);
    }
    return 0;
}