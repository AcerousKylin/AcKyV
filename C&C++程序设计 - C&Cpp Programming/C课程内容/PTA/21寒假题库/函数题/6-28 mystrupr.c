#include <stdio.h>

void mystrupr(char *s);

int main(void)
{
    char s[] = "ab+cdEFhijk@cqust";
    mystrupr(s);
    printf("%s", s);
    return 0;
}
/* 请在这里填写答案 */

void mystrupr(char *s)
{
    while (*s!='\0')
    {
        if (*s>='a' && *s<='z')
            *s -= 32;
        s++;
    }
}