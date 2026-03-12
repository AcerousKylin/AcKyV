//有一个正整型数k(2<=k<=10000)
//先把1到k中的所有奇数从小到大输出
//再把所有的偶数从小到大输出
#include<stdio.h>
int main(void)
{
    int n, k; int i, j; int o[50];
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &k);
        for (j=1; j<=k; j++)
            o[j] = j;
        printf("1");
        for (j=3; j<=k; j+=2)
            printf(" %d", o[j]);
        printf("\n2");
        for (j=4; j<=k; j+=2)
            printf("%d", o[j]);
        if (i!=k)
            printf("\n\n");
    }
    return 0;
}