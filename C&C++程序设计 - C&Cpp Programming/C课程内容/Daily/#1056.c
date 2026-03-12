//题干：先在第一行输入若干字符，随后在第二行输入单个字符
//要求检测第一行的字符中有多少个第二行的字符。
#include<stdio.h>
#include<math.h>
#include<string.h>
#define n 1000
int main(void)
{
    char str[n],ch;
    int i,j,v=0;
    gets(str); //获取字符串，以回车为开关
    j=strlen(str); //strlen(字符串变量); 用以计算字符串字符数
    scanf("%c",&ch);
    for(i=0;i<j;i++)
    {
        if(str[i]==ch)
            v++;
    }
    printf("%d\n",v);
    return 0;
}
