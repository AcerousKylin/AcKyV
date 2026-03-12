#include<stdio.h>
int main(void)
{
    int n, b1, b2, b3, b4;
    scanf("%d", &n);
    b1 = n / 1000; b2 = (n - b1 * 1000) / 100;
    b4 = n % 10;   b3 = ((n % 100) - b4) / 10;
    b1 = (b1 + 9) % 10;
    b2 = (b2 + 9) % 10;
    b3 = (b3 + 9) % 10;
    b4 = (b4 + 9) % 10;
    n = b3 * 1000 + b4 * 100 + b1 * 10 + b2;
    printf("%d", n);
    return 0;
}