#include<stdio.h>
int main(void)
{
    char digit[4]; char *pd;
    for (pd=digit+3; pd>digit; pd--);
        scanf("%c", pd);
    puts(digit);
    return 0;
}