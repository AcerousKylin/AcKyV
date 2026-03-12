#include<stdio.h>
int main(void)
{
    int a, b, c, n;
    scanf("%d", &n);
    a = n/100; //a=1
    b = (n-100*a)/10;
    c = n%10; //(n-100*a-10*b)
    printf("a=%d,b=%d,c=%d", a, b, c);
    return 0;
}
