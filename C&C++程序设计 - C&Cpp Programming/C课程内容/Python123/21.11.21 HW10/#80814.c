//分类统计字符，输入一个少于80字符、以回车为结尾的字符串
//分别统计其中数字字符、小写字符、大写字母及其他符号的个数
#include<stdio.h>
int main(void)
{
    char c[81]; int i, n=0, c1=0, c2=0, o=0;
    gets(c);
    for (i=0; c[i]!='\0'; i++)
    {
        if (c[i]>='0'&&c[i]<='9')
            n++;
        else if (c[i]>='A'&&c[i]<='Z')
            c1++;
        else if (c[i]>='a'&&c[i]<='z')
            c2++;
        else
            o++;
    }
    printf("数字：%d个\n大写字母：%d个\n小写字母：%d个\n其他字符：%d个\n", n, c1, c2, o);
    return 0;
}