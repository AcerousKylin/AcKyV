/*
本题要求编写程序，针对输入的N个字符串，输出其中最长的字符串。

输入格式：
输入第一行给出正整数N；随后N行，每行给出一个长度小于80的非空字符串，其中不会出现换行符，空格，制表符。

输出格式：
在一行中用以下格式输出最长的字符串：

The longest is: 最长的字符串
如果字符串的长度相同，则输出先输入的字符串。

输入样例：
5
li
wang
zhang
jin
xiang
结尾无空行

输出样例：
The longest is: zhang
结尾无空行
*/

// 输入转录储存 数组搭配比较 传递输出法
#include<stdio.h>
#include<string.h>
int main(void)
{
    char word[80], words[10000][80], *pw=word;
    int length[10000], *pl, longest=0, i;
    int n;
    scanf("%d", &n);
    for (pl=length, i=0; pl<length+n; pl++, i++)
    {
        int count=0;
        gets(word);
        strcpy(words[i], word);
        for (pw=word; *pw!='\0'; pw++)
            count++;
        *pl = count;
    }
    for (i=0; i<n; i++)
    {
        if (length[longest]<length[i])
            longest = i;
    }
    printf("The longest is: %s", words[longest]);
}