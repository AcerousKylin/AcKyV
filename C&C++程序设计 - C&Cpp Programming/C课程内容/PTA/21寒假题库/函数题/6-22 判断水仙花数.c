#include <stdio.h>

#define Cube(x) ...(略)...

/*
此处用法被称为宏函数，如:
#define Cube(x) x*x*x
简单来说，就是使用宏定义的方法编写函数
使用标识符,标识符就会被替换为后面的函数语句
单句语句执行&修改起来方便简洁
此处原题使用该方法编写了一个可以求输入值立方的宏函数
*/

int IsNarc(int x);

int main()
{
    int x;
    scanf("%d", &x);
    if (IsNarc(x))
    {
        puts("Yes");
    }
    else
    {
        puts("No");
    }
    return 0;
}

/* 你提交的代码将被嵌在这里 */

int IsNarc(int x)
{
    int i, temp=x, result=0;
    while (temp!=0)
    {
        result += Cube(temp%10);
        temp /= 10;
    }
    if (x==0 || x==1 || x!=result)
        return 0;
    if (x==result)
        return 1;
}