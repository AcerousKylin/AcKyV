#include <stdio.h>

#define MAXS 10

char *match( char *s, char ch1, char ch2 );

int main()
{
    char str[MAXS], ch_start, ch_end, *p;
    
    scanf("%s\n", str);
    scanf("%c %c", &ch_start, &ch_end);
    p = match(str, ch_start, ch_end);
    printf("%s\n", p);

    return 0;
}

/* 你的代码将被嵌在这里 */

char *match( char *s, char ch1, char ch2 )
{
    int start=0, end=0;
    char *p=NULL, *t=NULL;
    for (p=s; *p!='\0'; p++)
    {
        if (*p==ch1 && !start)
        {
            t = p;
            start = 1;
        }
        if (*p==ch2)
            end = 1;
        if (start)
            printf("%c", *p);
        if (end)
            break;
    }
    printf("\n");
    if (!start)
    {
        s[0]='\0';
        t = s;
    }
    return t;
}