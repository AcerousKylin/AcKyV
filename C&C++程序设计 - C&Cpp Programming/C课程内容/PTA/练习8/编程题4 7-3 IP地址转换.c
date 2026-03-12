/*
一个IP地址是用四个字节（每个字节8个位）的二进制码组成。请将32位二进制码表示的IP地址转换为十进制格式表示的IP地址输出。

输入格式：
输入在一行中给出32位二进制字符串。

输出格式：
在一行中输出十进制格式的IP地址，其由4个十进制数组成（分别对应4个8位的二进制数），中间用“.”分隔开。

输入样例：
11001100100101000001010101110010
结尾无空行

输出样例：
204.148.21.114
结尾无空行
*/

// 字符串转录 循环限制读取法
#include<stdio.h>
int main(void)
{
    char ipc[32];
    int ipn[32], *pip, bit, i, ip;
    scanf("%s", &ipc);
    for (i=0; i<32; i++)
        ipn[i] = ipc[i];
    for (i=0; i<32; i++)
        ipn[i] -= 48;
    for (bit=0; bit<=24; bit+=8)
    {
        ip = 0;
        for (pip=ipn+bit+7, i=0; pip>=ipn+bit, i<=7; pip--, i++)
        {
            if (*pip)
                ip += *pip*pow(2,i);
            if (!*pip)
                ip += 0;
        }
        printf("%d", ip);
        if (bit!=24)
            printf(".");
    }
    
    return 0;
}