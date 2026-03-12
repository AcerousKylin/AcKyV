//计算n！（递归）
#include<stdio.h>
double fact( int n )
{
    if (n < 0)
        return -1;
    else if (n==0||n==1)
        return 1;
    else
        return n*fact(n-1);
}
int main(void)
{
    int n; double result;
    scanf("%d", &n);
    result = fact(n);
    if (result==-1)
        printf("Invalid Value!");
    else
        printf("%.0f", result);
    return 0;
}