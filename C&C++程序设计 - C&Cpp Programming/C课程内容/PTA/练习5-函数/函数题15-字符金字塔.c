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

void CharPyramid( int n, char ch)
{
    int l, s, c;
    for (l=1; l<=n; l++)
    {
        for (s=n-l; s>0; s--)
            printf(" ");
        for (c=l; c>0; c--)
            printf("%c ", ch);
        if (l!=n)
            printf("\n");
    }
}