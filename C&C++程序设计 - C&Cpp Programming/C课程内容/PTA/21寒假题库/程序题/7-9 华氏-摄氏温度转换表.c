#include<stdio.h>
int main(void)
{
    int f; double c;
    int i, lower, upper;
    scanf("%d %d", &lower, &upper);
    if (lower>upper || upper>100)
    {
        printf("Invalid.\n");
        exit(0);
    }
    printf("fahr celsius\n");
    for (i=lower; i<=upper; i+=2)
    {
        f = i;
        c = 5.0 * (f - 32) / 9.0;
        printf("%d%6.1lf\n", f, c);
    }
    return 0;
}