/*
本题要求提取一个字符串中的所有数字字符（'0'……'9'），将其转换为一个整数输出。

输入格式：
输入在一行中给出一个不超过80个字符且以回车结束的字符串。

输出格式：
在一行中输出转换后的整数。题目保证输出不超过长整型范围。

输入样例：
free82jeep5
结尾无空行

输出样例：
825
结尾无空行
*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char digit[100], *pd=digit;
    long number=0;
    gets(digit);
    while (*pd!='\0')
    {
        if (*pd>='0' && *pd<='9')
            number = number * 10 + *pd-48;
        pd++;
    }
    printf("%ld", number);
    return 0;
}