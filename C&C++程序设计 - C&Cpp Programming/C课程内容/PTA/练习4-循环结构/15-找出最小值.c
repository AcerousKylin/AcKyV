//找出给定一系列整数中的最小值
#include<stdio.h>
int main(void)
{
    int i, n, value, min;
    scanf("%d", &n);
    for (i=0; i<n; i++)
    {
        scanf("%d", &value);
        if (value<=min||i==0)
            min = value;
        else;
    }
    printf("min = %d", min);
    return 0;
}