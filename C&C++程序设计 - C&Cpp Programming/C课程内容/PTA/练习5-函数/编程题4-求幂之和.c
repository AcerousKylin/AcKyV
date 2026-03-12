#include<stdio.h>
#include<math.h>
int main(void)
{
    int item, sum=0, n, i;
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
        item = pow(2, i);
        sum += item;
    }
    printf("result = %d", sum);
    return 0;
}