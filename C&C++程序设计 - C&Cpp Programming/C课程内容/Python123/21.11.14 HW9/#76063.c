//交换两个数
#include <stdio.h>
int a,b;
void swap(void)
{
    int i;
    i = a; a = b; b = i;
}
int main(void)
{
    scanf("%d,%d", &a, &b);
    swap();
    printf("a=%d,b=%d", a, b);
    return 0;
}