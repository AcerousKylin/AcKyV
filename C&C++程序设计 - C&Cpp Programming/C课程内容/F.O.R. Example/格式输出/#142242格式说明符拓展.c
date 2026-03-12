#include <stdio.h>
int main(void)
{ 
    int a=1234;
    printf("\n01.a=%d.a=%#d", a, a);
    printf("\n02.a=%o.a=%#o", a, a);
    printf("\n03.a=%x.a=%#x", a, a);
    printf("\n05.a=%-8X.a=%#8X", a, a);
    printf("\n06.a=%08X.a=%#08X", a, a);
    /*
    %#？
    #代表标准格式输出
    其输出结果如下:

    01.a=1234.a=1234 // 标准化整型输出
    02.a=2322.a=02322 // 标准化八进制输出
    03.a=4d2.a=0x4d2 // 标准化十六进制小写输出
    05.a=4D2     .a=   0X4D2 // 标准化十六进制大写输出
    06.a=000004D2.a=0X0004D2 // 标准化0占位十六进制输出
    */
    return 0;
}