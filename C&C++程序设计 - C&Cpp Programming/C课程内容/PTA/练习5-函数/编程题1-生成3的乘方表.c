#include<stdio.h>
int main(void)
{
    int i, n;
    scanf("%d", &n);
    for (i=0; i<=n; i++)
        printf("pow(3,%d) = %.0f\n", i, pow(3,i));
    return 0;
}