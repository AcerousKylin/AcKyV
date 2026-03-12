//编程输入正整数N（N<100），输出一个N阶下三角方阵
#include<stdio.h>
int main(void)
{
    int n, i, j, k;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        for (j=n-i; j>=1; j--)
            printf("   ");
        for (k=1; k<=i; k++)
            printf("%3d", k);
        printf("\n");
    }
    return 0;
}