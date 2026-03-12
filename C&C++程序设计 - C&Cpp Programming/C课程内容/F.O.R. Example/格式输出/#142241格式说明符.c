#include <stdio.h>
int main(void)
{ 
    int a=1234, i; char c;
    float f=3.141592653589;
    double x=0.12345678987654321;
    i=12;  c='\x41';
    // c的值是ASCII码值为十六进制数0x41的字符
    printf("\n01.a=%d.",       a);
    // %d整型标准输出

    printf("\n02.a=%6d.",      a);
    printf("\n03.a=%06d.",     a);
    printf("\n04.a=%2d.",      a);
    printf("\n05.a=%-6d.",     a);
    /* %md
    m>0:
        数据长度<m,右对齐,左补空格; 02
        数据长度>m,按实际宽度输出. 04
        此外,m有前导符0时:
            数据长度<m,左空补0; 03
            数据长度>m，按实际宽度输出.
    m<0:
        在域内左对齐. 05
    */

    printf("\n06.f=%f.",       f);
    printf("\n07.f=%6.4f.",    f);
    printf("\n08.x=%lf.",      x);
    printf("\n09.x=%18.16lf.", x);
    /* 基本同上
        %.nf
            精度修饰符位于最小域宽修饰符之后(n>=0且为整数)
            对于浮点数，指定输出浮点数的小数数位
            注意控制m和n的数值
        %lf 修饰格式符d o x u时，输出long型
    */

    printf("\n10.c=%c.",       c);
    printf("\n11.c=%x.",       c);
    /*
        %c 输出一个字符
        %x 以无符号十六进制整数+小写字母形式(十六进制数包含字母)
    */
   
    printf("\n12.%s."   ,"ABCDEFGHIJK");
    printf("\n13.%4s."  ,"ABCDEFGHIJK");
    printf("\n14.%14s.","ABCDEFGHIJK");
    printf("\n15.%-14s.","ABCDEFGHIJK");
    printf("\n16.%4.6s.","ABCDEFGHIJK");
    /*
        %ms同上
        %.ns 对于字符串，指定从字符串左侧开始截取的子串字符个数
    */
    return 0;
}