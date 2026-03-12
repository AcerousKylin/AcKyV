/*在这里给出函数被调用进行测试的例子。例如:*/
#include <stdio.h>

char *mystrcat(char *s1, const char *s2);

int main()
{
    char a[100] = "abcd", b[60], c[30];
    scanf("%s", b);
    scanf("%s", c);
    mystrcat(a, mystrcat(b, c));
    puts(a);
    return 0;
}

/* 请在这里填写答案 */

char *mystrcat(char *s1, const char *s2)
{
    int i, j;
    for (i=0; s1[i]!='\0'; i++);
    for (j=0; s2[j]!='\0'; i++, j++)
        s1[i] = s2[j];
    s1[i] = '\0';
    return s1;
}