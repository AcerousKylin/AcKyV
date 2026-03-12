// 在这里给出函数被调用进行测试的例子。例如：
#include <stdio.h>

int countAlpha(const char *s);

int main(void)
{
    char s[100];
    gets(s);
    printf("%d", countAlpha(s));
    return 0;
}

/* 请在这里填写答案 */

int countAlpha(const char *s)
{
    int count=0;
    char *p;
    for (p=s; *p!='\0'; p++)
    {
        if (*p>='A' && *p<='Z')
            count++;
        if (*p>='a' && *p<='z')
            count++;
    }
    return count;
}