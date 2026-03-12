#include <stdio.h>

char *mystrcpy(char *s1, const char *s2);

int main(void)
{
    char str1[30], str2[30], str3[30];
    gets(str3);
    mystrcpy(str1, mystrcpy(str2, str3));
    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);
    printf("str3: %s\n", str3);
    return 0;
}

/* 请在这里填写答案 */

char *mystrcpy(char *s1, const char *s2)
{
    char *p=s1;
    while(*p++ = *s2++);
    *p = '\0';
    return s1;
}