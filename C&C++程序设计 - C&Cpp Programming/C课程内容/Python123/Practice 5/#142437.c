//输入一串以.结尾的字符串，提取出数字字符组成的整数
//如果不包含数字，输出0
//整数输出版本
#include<stdio.h>
int main(void)
{
    char ch; int n;
    while((ch=getchar())!='.')
    {
        if (ch>='0'&&ch<='9')
            n = n*10+ch-48;
    }
    printf("%d", n);
    return 0;
}

//字符输出版本