// 在这里给出函数被调用进行测试的例子。例如：
#include <stdio.h>

int myatoi(const char *s);

int main(void)
{
    char s1[30] = "ab6@0gap49$";
    char s2[30] = "5rt1";
    int x = myatoi(s1);
    int y = myatoi(s2);
    int z = x + y;
    printf("%d + %d = %d\n", x, y, z);
    return 0;
}


/* 请在这里填写答案 */

int myatoi(const char *s)
{
    int number[10];
    int i=0, result=0, flag=0, j;
    while (*s!='\0')
    {
        if(*s>='0' && *s<='9')
        {
            number[i++] = *s - 48;
            flag = 1;
        }
        s++;
    }
    j = i; i = 0;
    if (!flag)
        return 0;
    while(i!=j)
    {
        result *= 10;
        result += number[i++];
    }
    return result;
}