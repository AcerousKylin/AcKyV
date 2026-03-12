#include<stdio.h>
int main(void)
{
    int n, o=1, m=0, p=0, sum=0, month=1; //o=origin m=midst p=parent
    int m1;
    scanf("%d", &n);
    while (sum<n)
    {
        month++;
        m1 = m; m = o;
        p += m1;
        o = p;
        sum = o+m+p;
    }
    if (n==1) month=1;
    printf("%d", month);
    return 0;
}
