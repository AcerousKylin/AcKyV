/*
输入最少1个最多不超过4个整数，输出他们的和。
*/

#include<stdio.h>
int main(void)
{
    int n, sum=0;
    while (~scanf("%d", &n))
        sum += n;
    printf("%d", sum);
    return 0;
}