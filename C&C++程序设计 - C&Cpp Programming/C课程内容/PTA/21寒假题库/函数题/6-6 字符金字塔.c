#include <stdio.h>

void CharPyramid( int n, char ch );

int main()
{    
    int n;
    char ch;

    scanf("%d %c", &n, &ch);
    CharPyramid(n, ch);
    
    return 0;
}

/* 请在这里填写答案 */

void CharPyramid( int n, char ch )
{
    int i, j;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<n-i; j++)
            printf(" ");
        for(j=0; j<i; j++)
            printf("%c ", ch);
        printf("\n");
    }
}