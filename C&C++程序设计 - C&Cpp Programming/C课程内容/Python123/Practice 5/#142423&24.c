//指定范围内的所有完数，如果没有，输出Not Found.
//主函数版（超级慢）
#include<stdio.h>
int main(void)
{
    long a, b, number, factor, sum, count=0;
    scanf("%ld %ld", &a, &b);
    for (number=a; number<=b; number++)
    {
        sum = 0;
        for (factor=1; factor<number; factor++)
        {
            if (number%factor==0)
                sum += factor;
        }
        if (sum==number)
        {
            count++;
            if (count==1)
                printf("%d", number);
            else
                printf(" %d", number);
        }
    }
    if (count==0)
        printf("Not Found.");
    return 0;
}

//函数版（稍快）
#include<stdio.h>
int factorsum( int number )
{
	int sum = 0, i;
    for (i = 1; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			sum += i;
		}
	}
	return sum;
}
int main(void)
{
	int flag = 0, count = 0, m, n, i;
	scanf("%d %d", &m, &n);
	for (i = m; i <= n; i++)
	{
		if(factorsum(i) == i)
		{
            if (count==0)
			    printf("%d", i);
			if (count!=0)
			    printf(" %d", i);
			count++;
		}
	}
	if(count==0)
		printf("Not Found.\n");
	return 0;
}

//输入一个不小于6的正整数N(N<99999999)
//输出它是不是完数("YES" or "NO")
#include<stdio.h>
int main(void)
{
    int number, factor, sum;
    scanf("%d", &number);
        for (factor=1; factor<number; factor++)
        {
            if (number%factor==0)
                sum += factor;
        }
    if (sum==number)
        printf("YES");
    if (sum!=number)
        printf("NO");
    return 0;
}