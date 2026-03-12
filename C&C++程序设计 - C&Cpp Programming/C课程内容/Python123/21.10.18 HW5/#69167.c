//输入区间，检测奇数累加
#include<stdio.h>
int main(void)
{
    int n, number, sum=0;
    scanf("%d", &n);
    for (number=1; number<=n; number++)
    {
        if (number%2==1)
            sum += number;
    }
    printf("%d", sum);
    return 0;
}

#include<stido.h>
int main(void)
{
    int n, number, sum;
    scanf("%d", &n);
    for (number=1; number<=n; number+=2)
    {
        sum += number;
    }
    printf("%d", sum);
    return 0;
}