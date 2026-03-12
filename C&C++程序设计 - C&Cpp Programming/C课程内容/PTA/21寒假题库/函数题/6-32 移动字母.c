#include <stdio.h>
#include <string.h>

#define MAXS 10

void Shift( char s[] );

void GetString( char s[] ); /* 实现细节在此不表 */

int main()
{
    char s[MAXS];

    GetString(s);
    Shift(s);
    printf("%s\n", s);
    
    return 0; 
}

/* 你的代码将被嵌在这里 */

void Shift( char s[] )
{
    int i, j, k;
    char p[3];
    for (i=0; i<3; i++)
        p[i] = s[i];
    for (i=0; s[i+3]!='\0'; i++)
        s[i] = s[i+3];
    for (j=i, k=0; k<3; j++, k++)
        s[j] = p[k];
}