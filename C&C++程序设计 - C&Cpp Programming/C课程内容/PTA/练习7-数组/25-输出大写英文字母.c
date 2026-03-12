/*
本题要求编写程序，顺序输出给定字符串中所出现过的大写英文字母，每个字母只输出一遍；若无大写英文字母则输出“Not Found”。

输入格式：
输入为一个以回车结束的字符串（少于80个字符）。

输出格式：
按照输入的顺序在一行中输出所出现过的大写英文字母，每个字母只输出一遍。若无大写英文字母则输出“Not Found”。

输入样例1：
FONTNAME and FILENAME
结尾无空行

输出样例1：
FONTAMEIL
结尾无空行

输入样例2：
fontname and filrname

输出样例2：
Not Found
*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    char ori[100], bucket[100];
    char *po;
    int i=0, j, flag=0;
    gets(ori);
    for (po=ori; *po!='\0'; po++)
    {
        if (*po>='A' && *po<='Z')
        {
            flag = 1;
            bucket[i] = *po;
            for (j=0; j<i; j++)
            {
                if (bucket[i]==bucket[j])
                {
                    i--;
                    break;
                }
            }
            i++;
        }
    }
    bucket[i] = '\0';
    if (flag)
        for (i=0; bucket[i]!='\0'; i++)
            printf("%c", bucket[i]);
    else
        printf("Not Found");
    return 0;
}