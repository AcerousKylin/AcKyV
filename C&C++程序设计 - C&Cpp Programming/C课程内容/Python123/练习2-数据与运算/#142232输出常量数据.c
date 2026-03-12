/*
第一行输出2049的十进制、八进制、十六进制形式
第二行输出半径为2的圆的面积
第三行输出：我学习我快乐
请恰当使用格式说明符完成
*/

#include<stdio.h>
#define pi 3.1415926585
int main(void)
{
    int a=2049; double r=2;
    printf("%d 0%o 0x%x\n", a, a, a); 
    //%o是八进制输出格式符; %x是十六进制输出格式符
    printf("%.6f\n", pi*r*r);
    printf("我学习我快乐");
    return 0;
}