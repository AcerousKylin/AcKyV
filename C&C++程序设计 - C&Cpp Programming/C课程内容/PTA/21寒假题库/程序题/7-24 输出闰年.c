#include<stdio.h>
int main(void)
{
    int i, sign, flag=0;
    scanf("%d", &sign);
    if (sign<2001 || sign>2100)
        printf("Invalid year!");
    if (sign>=2001 && sign<2004)
        printf("None");
    if (sign>=2004 && sign<=2100)
        for (i=2004; i<=sign; i+=4)
            printf("%d\n", i);
    return 0;
}