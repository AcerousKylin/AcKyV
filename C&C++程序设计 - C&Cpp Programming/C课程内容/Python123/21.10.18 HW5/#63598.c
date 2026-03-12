//输入数字数量，检测偶数累加
#include<stdio.h>
int main(void)
{
    int n, number, sum=0, i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        scanf("%d", &number);
        if (number%2==0)
            sum += number;
        else;
    }
    printf("%d", sum);
    return 0;
}