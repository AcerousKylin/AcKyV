#include <stdio.h>
#define MAXN 20

void delchar( char *str, char c );
void ReadString( char s[] ); /* 由裁判实现，略去不表 */

int main()
{
    char str[MAXN], c;

    scanf("%c\n", &c);
    ReadString(str);
    delchar(str, c);
    printf("%s\n", str);
    
    return 0;
}

/* 你的代码将被嵌在这里 */

void delchar( char *str, char c )
{
    char *pp;
    int i=0;
    for(pp=str; pp+i<str+88; pp++)
    {
        while (*(pp+i)==c)
        {
            i++;
        }
        *pp = *(pp+i);
    }
}