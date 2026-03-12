#include<stdio.h>
void top( int *p )
{
    int i, s=1, flag=1;
    for (i=1; flag; i++)
    {
        if ( *p>=s && *p<s+2*( 2*i+1 ) )
        {
            p[1] = p[0] - s;
            p[0] = 2 * (i-1) + 1;
            flag = 0;
        }
        s += 2 * (2 * i + 1);
    }
}

int main(void)
{
    int p[2];
    char ch;
    scanf("%d %c", &p, &ch);
    top(p);

    int i, j;
    for (i=p[0]; i>0; i-=2)
    {
        for (j=(p[0]-i)/2; j>0; j--)
            printf(" ");
        for (j=0; j<i; j++)
            printf("%c", ch);
        printf("\n");
    }

    for (i=3; i<=p[0]; i+=2)
    {
        for (j=(p[0]-i)/2; j>0; j--)
            printf(" ");
        for (j=0; j<i; j++)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d", p[1]);
    return 0;
}