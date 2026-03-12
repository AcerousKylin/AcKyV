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

void hollowPyramid( int n )
{
    int l, s, d;
    if (n==1)
    {
        printf("1");
        return 0;
    }
    for (l=1; l<=n; l++)
    {
        if (l==1)
        {
            for (s=n-1; s>0; s--)
                printf(" ");
            printf("1\n");
        }
        if (l!=n && l!=1)
        {
            for (s=n-l; s>0; s--)
                printf(" ");
            for (d=2; d>0; d--)
            {
                printf("%d", l);
                if (d!=1)
                    for (s=(l-1)*2-1; s>0; s--)
                        printf(" ");
            }
            printf("\n");
        }
        if (l==n)
            for (d=2*l-1; d>0; d--)
                printf("%d", l);
    }
}