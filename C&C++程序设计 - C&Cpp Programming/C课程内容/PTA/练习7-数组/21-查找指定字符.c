/*
本题要求编写程序，从给定字符串中查找某指定的字符。

输入格式：
输入的第一行是一个待查找的字符。第二行是一个以回车结束的非空字符串（不超过80个字符）。

输出格式：
如果找到，在一行内按照格式“index = 下标”输出该字符在字符串中所对应的最大下标（下标从0开始）；否则输出"Not Found"。

输入样例1：
m
programming
结尾无空行

输出样例1：
index = 7
结尾无空行

输入样例2：
a
1234

输出样例2：
Not Found
*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char c[100], target;
    int index=-1, i; // 下标标识变量注意初值为-1,i为计数器
    scanf("%c", &target); // 先输入待查字符
    getchar(); // 注意target后的回车
    gets(c); // 输入字符串
    for (i=0; c[i]!='\0'; i++)
        if (c[i]==target) // 查找指定字符
            index = i; // 有则记录下标,注意,此处记录了最大下标
    if (index==-1) // 如果没有,index仍然为-1
        printf("Not Found");
    else // 否则将下标输出
        printf("index = %d", index);
    return 0;
}