// 统计给定区间内的三位数中有两位数字相同的完全平方数
// （如144、676）的个数

#include <stdio.h>
#include <math.h>

int search( int n );

int main()
{
    int number;

    scanf("%d",&number);
    printf("count=%d\n",search(number));

    return 0;
}


/* 你的代码将被嵌在这里 */

int search( int n )
{
    int i, count=0;
    for(i=11; i<=sqrt(n); i++)
    {
        if (i*i%10==i*i/100 || i*i%10==(i*i/10)%10 || (i*i/10)%10==i*i/100)
            count++;
    }
    return count;
}