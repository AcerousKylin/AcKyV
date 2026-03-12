/*
输入一个以#结束的字符串，本题要求滤去所有的非十六进制字符（不分大小写），组成一个新的表示十六进制数字的字符串，
然后将其转换为十进制数后输出。如果在第一个十六进制字符之前存在字符“-”，则代表该数是负数。

输入格式：
输入在一行中给出一个以#结束的非空字符串。

输出格式：
在一行中输出转换后的十进制数。题目保证输出在长整型范围内。

输入样例：
+-P-xf4+-1!#
结尾无空行

输出样例：
-3905
结尾无空行
*/

#include<stdio.h>
#include<string.h>
#include<math.h>
int main(void)
{
    char ori[1000];
    char *po, *pp;
    int flag=0, temp[80], flag=1, i=0, j, sign=1;
    long result=0;
    gets(ori); // 获得字符串
    for (po=ori; *po!='#'; po++)  // 遍历字符串
    {
        if (flag && *po=='-')
        {
            sign = -1; // 有则更改符号标识变量
            flag;
        }
        if (*po>='a' && *po<='f') //小写a~f
        {
            temp[i] = *po - 87; // 将小写字母字符从ASCII码值转为数值,存入数组
            i++;
        }
        if (*po>='A' && *po<='F') // 大写A~F
        {
            temp[i] = *po - 55; // 将大写字母字符从ASCII码值转为数值,存入数组
            i++;
        }
        if (*po>='0' && *po<='9') // 数字0~9
        {
            temp[i] = *po - 48; // 将数字字符从ASCII码值转为数值,存入数组
            i++;
        }
    }
    for (j=0; j<i; j++)
        result += pow(16, j)*temp[i-1-j]; // 逆序读取数组,从低位计算累加
    printf("%ld", sign*result); // 根据符号标识变量输出正或负值
    return 0;
}