/*
本题要求统计一个整型序列中出现次数最多的整数及其出现次数。

输入格式：
输入在一行中给出序列中整数个数N（0<N≤1000），以及N个整数。数字间以空格分隔。

输出格式：
在一行中输出出现次数最多的整数及其出现次数，数字间以空格分隔。题目保证这样的数字是唯一的。

输入样例：
10 3 2 -1 5 3 4 3 0 3 2
结尾无空行

输出样例：
3 4
结尾无空行
*/

// 桶排序（数据值限小）
/*
#include<stdio.h>
#define Zero 1
#define MAX 1000000
int main(void)
{
    long long n, i, max=0;
    long long number, bucket[MAX]={0};
    scanf("%lld", &n);
    for (i=0; i<n; i++)
    {
        scanf("%lld", &number);
        bucket[Zero+number]++;
    }
    for (i=0; i<MAX; i++)
    {
        if (bucket[max]<bucket[i])
            max = i;
    }
    printf("%lld %lld", max-Zero, bucket[max]);
    return 0;
}
*/

// 双数组
#include<stdio.h>
int main(void)
{
    int number_time[2][1000]={0}; // 初始化二维数组,计数行为0
    int n, n_, i, j, max=0;
    scanf("%d", &n);
    n_ = n; // 下面合并相同数值需要改变循环结束条件,而输出时也需要n,需要另存
    for (i=0; i<n_; i++)
    {
        scanf("%d", &number_time[0][i]); // 将数据存在第一行
        for (j=0; j<i; j++) // 准备查重计数
        {
            if (number_time[0][i]==number_time[0][j]) // 如果前面存过相同的数
            {
                number_time[1][j]++; // 前面同数值下计数+1
                i--; // 调整循环计数,下次循环将这个重复的值覆盖
                // 注意:最后一个值是出现过的值时，由于该值下计数数值为0,必定小于前面同数值下的 计数值,所以无需处理
                n_--; // 循环结束条件也相应减少,结束输入;否则死循环
            }
        }
    }
    for (i=0; i<n; i++) // 找出计数值最大的下标
    {
        if (number_time[1][max]<number_time[1][i])
            max = i;
    }
    printf("%d %d", number_time[0][max], number_time[1][max]+1); // 由于所有计数值初始值为0， 所以+1
    return 0;
}