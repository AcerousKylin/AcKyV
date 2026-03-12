/*在这里给出函数被调用进行测试的例子。例如:*/
#include <stdio.h>

char* mystrcat(char *s1, const char *s2);

int main(void)
{
    char str1[100] = "Winter ", str2[60] = "is ", str3[30] = "comming.";
    mystrcat(str1, mystrcat(str2, str3));
    printf("%s", str1);
    return 0;
}

/* 请在这里填写答案 */

char* mystrcat(char *s1, const char *s2)
{
    char *p=s1;
    while (*++p);
    while (*p++ = *s2++);
    *p = '\0';
    return s1;
}