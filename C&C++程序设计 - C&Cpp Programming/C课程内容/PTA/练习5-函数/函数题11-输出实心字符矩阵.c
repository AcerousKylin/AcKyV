#include <stdio.h>

void matrix(int length, int width, char ch);

int main()
{    
    int length, width;
    char ch;

    scanf("%d %d %c", &length, &width, &ch);
    matrix(length, width, ch);

    return 0;
}

/* 请在这里填写答案 */

void matrix(int length, int width, char ch)
{
    int l, w;
    for (w=1; w<=width; w++)
    {
        for (l=1; l<=length; l++)
            printf("%c", ch);
        printf("\n");
    }
}