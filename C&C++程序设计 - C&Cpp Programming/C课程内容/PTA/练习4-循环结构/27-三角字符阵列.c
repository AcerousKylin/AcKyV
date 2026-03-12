//输出n行由大写字母A开始构成的三角形字符阵列
#include<stdio.h>
int main(void)
{
    int n, i, o;
    char ch='A';
    scanf("%d", &n);
    for (i=n; i>0; i--)
    {
        for (o=i-1; o>=0; o--)
        {
            putchar(ch);
            putchar(' ');
            if (i!=1&&o==0) putchar('\n');
            ch++;
        }
    }
}