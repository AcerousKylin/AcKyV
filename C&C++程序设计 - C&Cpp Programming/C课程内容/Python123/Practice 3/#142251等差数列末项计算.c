#include<stdio.h>
int main(void)
{
    int a1, a2, n, q;
    scanf("%d %d %d", &a1, &a2, &n);
    q = a2 - a1;
    printf("%d", a1+q*(n-1));
    return 0;
}