#include <stdio.h>
#define MAXS 15

void StringCount( char *s );
void ReadString( char *s ); /* 由裁判实现，略去不表 */

int main()
{
    char s[MAXS];

    ReadString(s);
    StringCount(s);

    return 0;
}

/* Your function will be put here */

void StringCount( char *s )
{
    int big=0, small=0, space=0, digit=0, other=0;
    char *p;
    for (p=s; *p!='\0'; p++)
    {
        if (*p>='A' && *p<='Z')
            big++;
        else if (*p>='a' && *p<='z')
            small++;
        else if (*p==' ')
            space++;
        else if (*p>='0' && *p<='9')
            digit++;
        else
            other++;
    }
    printf("%d %d %d %d %d", big, small, space, digit, other);
}