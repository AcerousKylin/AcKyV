/*
本题要求编写程序，将给定字符串去掉重复的字符后，按照字符ASCII码顺序从小到大排序后输出。

输入格式：
输入是一个以回车结束的非空字符串（少于80个字符）。

输出格式：
输出去重排序后的结果字符串。

输入样例：
ad2f3adjfeainzzzv
结尾无空行

输出样例：
23adefijnvz
结尾无空行
*/

#include<stdio.h>
#include<string.h>
int main(void)
{
    int bucket[2][255]={0};
    int i;
    char ori[100], *po;
    for (i=0; i<255; i++)
        bucket[0][i] = i;
    gets(ori);
    for (po=ori; *po!='\0'; po++)
    {
        for (i=0; i<255; i++)
        {
            if (*po==bucket[0][i])
            {
                bucket[1][i]+=1;
                break;
            }
        }
    }
    for (i=0; i<255; i++)
        if (bucket[1][i]>0)
            printf("%c", bucket[0][i]);
    return 0;
}