#include <stdio.h>
#define MAXS 30

char *search(char *s, char *t);
void ReadString( char s[] ); /* 裁判提供，细节不表 */

int main()
{
    char s[MAXS], t[MAXS], *pos;
    
    ReadString(s);
    ReadString(t);
    pos = search(s, t);
    if ( pos != NULL )
        printf("%d\n", pos - s);
    else
        printf("-1\n");

    return 0;
}

/* 你的代码将被嵌在这里 */

#include<string.h>

char *search( char *s, char *t )
{
    int flag=0;
    char *ps=NULL, *target=NULL;
    for (ps=s; *ps!='\0'; ps++)
    {
        if (*ps==t[0])
        {
            int i;
            target = ps;
            for (i=0; i<strlen(t); i++, ps++)
            {
                if (*ps!=t[i])
                {
                    ps--;
                    target = NULL;
                    flag = 0;
                    break;
                }
                flag = 1;
            }
        }
        if (flag)
            break;
    }
    return target;
}