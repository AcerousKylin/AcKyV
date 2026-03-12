#include<stdio.h>
int main(void)
{
    int a, b, c, d;
    a = 5; b = 6;
    d = (a>=8) || (b=19)<90; // 此处a>=8不成立,b=19得以执行,条件成立,d=1
    printf("d=%d,b=%d\n", d, b); // d=1,b=19
    a = 5; b = 6;
    d = (a>=4) || (b=19)<90; // 此处a>=4成立,||已经成立,b=19并未执行,条件仍然成立,d=1
    printf("d=%d,b=%d", d, b); // d=1,b=6
    return 0;
}