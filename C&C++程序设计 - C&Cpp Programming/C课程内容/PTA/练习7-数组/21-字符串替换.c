/*
本题要求编写程序，将给定字符串中的大写英文字母按以下对应规则替换：

原字母	对应字母
A	Z
B	Y
C	X
D	W
…	…
X	C
Y	B
Z	A
输入格式：
输入在一行中给出一个不超过80个字符、并以回车结束的字符串。

输出格式：
输出在一行中给出替换完成后的字符串。

输入样例：
Only the 11 CAPItaL LeTtERS are replaced.
结尾无空行

输出样例：
Lnly the 11 XZKRtaO OeGtVIH are replaced.
结尾无空行
*/

#include<stdio.h>
#include<string.h>

int main(void)
{
    char c[100], big[26], *pc; // 待输入字符串,大写字母转译本,指针
    int i; // 计数器
    gets(c); // 输入字符串
    for (i=0; i<26; i++) // 制作转译本
        big[i] = 'A' + i;
    for (pc=c; *pc!='\0'; pc++) // 开始替换
    {
        if (*pc>=65 && *pc<=90) // 只替换大写字母
        {
            *pc -= 65; // 先转换为下标
            printf("%c", big[25-*pc]); // 题目要求的转换方式
        }
        else
            printf("%c", *pc); // 其他字符照常输出
    }
    return 0;
}