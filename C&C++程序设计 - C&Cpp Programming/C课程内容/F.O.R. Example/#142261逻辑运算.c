#include<stdio.h>
int main(void)
{
    int a, b, c, d;
    a = 5; b = 6;
    c = (a<=8)&&(b=7)>5; // 运算顺序 (=), > (<=), &&, =
    printf("c=%d,b=%d\n",c,b); // c=1, b=7
    a = 5; b = 6;
    c = (a<=4)&&(b=7)>5; // 运算顺序同上,由于&&结果为0，赋值取消?
    printf("c=%d,b=%d",c,b); // c=0, b=6
    return 0;
}