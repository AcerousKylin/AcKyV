/*在这里给出函数被调用进行测试的例子。例如:*/
#include <stdio.h>

int mystrlen(const char *s);

int main(void)
{
    char s[30];
    gets(s);
    printf("%d", mystrlen(s));
    return 0;
}

/* 请在这里填写答案 */

int mystrlen(const char *s)
{
    int count=0;
    while(*s++)
        count++;
    return count;
}