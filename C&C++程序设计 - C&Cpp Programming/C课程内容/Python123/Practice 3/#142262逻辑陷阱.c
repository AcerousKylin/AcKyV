#include<stdio.h>
int main(){
    int a,b,c,d;
    a=5; b=6;
    d=(a>=8)||(b=19)<90; //d作为判断输出0或1，下同
        printf("d=%d,b=%d\n",d,b); //输出判断值和结果
    a=5; b=6;
    d=(a>=4)||(b=19)<90;
        printf("d=%d,b=%d",d,b);
    return 0;
}