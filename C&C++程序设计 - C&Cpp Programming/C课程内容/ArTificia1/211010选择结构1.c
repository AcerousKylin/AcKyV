/*
热知识：1度电是1kw·h（电功符号用k代替）；
        且中国额定电压为220V。
问：一家用电器额定功率为x瓦，
    已知其他用电器总额定功率为3450瓦；
求：一天该用电器用多少度电（保留两位小数）；
        公式：k=24（w-3450）/1000
求：如果一天用电y度，
    请问这一天的平均总功率是多少（保留两位小数）？
        公式：w=1000k/24
若输入负数或运算中出现负数，则输出“Invalid Value!”；
输入其他单位数值则输出“Error!”

样例输入1：
4000W
样例输出1：
13.20K
样例输入2：
60.5K
样例输出2：
2520.83W
样例输入3：
2050W
样例输出3：
Invalid Value!
样例输入4：
-273.15C
样例输出4：
Error!
*/
#include<stdio.h>
int main(void)
{
    int x;
    float k, w;
    char ch;
    scanf("%d%c", x, ch);
    if (x<0)
        printf("Invalid Value!");
    else if (x>=0&&ch=='W')
    {
        if (x>=3450)
        {
            k = 24*(x-3450)/100;
            printf("%.2fW", k);
        }
        else printf("Invalid Value!");
    }
    else if (ch=='K')
    {
        if (x>=0)
        {
            w = 1000*k/24;
            printf("%.2fK", w);
        }
    }
    else
        printf("Error!");
    return 0;
}