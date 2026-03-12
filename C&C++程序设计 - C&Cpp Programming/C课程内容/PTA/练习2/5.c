#include<stdio.h>
int main(void)
{
    int o, t, h, n;
    n = 152;
    h = n/100;
    t = (n-100*h)/10;
    o = n%10;
    printf("%d = %d + %d*10 + %d*100", n, o, t, h);
    return 0;
}