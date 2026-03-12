#include<stdio.h>
int main(void)
{
    int sort[2][10]; // 定义二维数组 存储10个数字及其出现个数
    int i, j, n, number, mark=0; // mark需要初始化
    scanf("%d", &n);
    for (i=0; i<10; i++) // 初始化二维数组第一行固定的十个数字和第二行的0
    {
        sort[0][i] = i;
        sort[1][i] = 0;
    }
    for (i=0; i<n; i++)
    {
        scanf("%d", &number);
        while (number!=0) // 读取单个数的各位数字
        {
            for (j=0; j<10; j++)
            {
                if (number%10==j) // 每有一个数字就为数组中数字下一行的值+1
                {
                    sort[1][j]++;
                    break;
                }
            }
            number /= 10; // 为了达成单个数字读入完毕的条件
        }
    }
    for (i=0; i<10; i++)
    {
        if (sort[1][i]>sort[1][mark]) // 先找到出现最高出现次数
        {
            mark = i;
        }
    }
    printf("%d:", sort[1][mark]); // 打印出现最高出现次数
    for (i=0; i<10; i++)
    {
        if (sort[1][i]==sort[1][mark]) // 再找出同样出现同样多次数的数
        {
            printf(" %d", sort[0][i]); // 并打印
        }
    }
    printf("\n");
    return 0;
}