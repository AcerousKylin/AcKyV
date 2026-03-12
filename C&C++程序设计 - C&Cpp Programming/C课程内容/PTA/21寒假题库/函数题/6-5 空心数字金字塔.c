#include <stdio.h>

void hollowPyramid ( int n );

int main()
{    
    int n;

    scanf("%d", &n);
    hollowPyramid ( n );

    return 0;
}

/* 你的代码将被嵌在这里 */

void hollowPyramid ( int n )
{
    int i, j, temp=2;
    for (i=1; i<n; i++)
        printf(" ");
    if (n!=1)
        printf("1\n");
    for (i=1; i<=n-2; i++)
    {
        for (j=0; j<n-1-i; j++)
            printf(" ");
        printf("%d", temp);
        for (j=0; j<2*i-1; j++)
            printf(" ");
        printf("%d\n", temp++);
    }
    for(i=0; i<2*n-1; i++)
        printf("%d", n);
}