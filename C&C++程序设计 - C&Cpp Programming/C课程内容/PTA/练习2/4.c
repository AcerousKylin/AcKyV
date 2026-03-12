#include<stdio.h>
int main(void)
{
    int a0, b0, c0, a1, a2, a3, b1, b2, c;
    a0 = 8;
    b0 = 9;
    c0 = 10;
    a1 = a0/3;
    b1 = (b0+a1)/3;
    a2 = a1+b1;
    c = (c0+b1+a1)/3;
    a3 = a2+c;
    b2 = b1+c;
    printf("%d %d %d", a3, b2, c);
    return 0;
}