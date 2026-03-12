/*
交换规则
先将输入的一系列整数中的最小值与第一个数交换
然后将最大值与最后一个数交换
最后输出交换后的序列
*/

#include<stdio.h>
int main(void)
{
    int n;
    scanf("%d", &n);
    int number[n], i, biggest, smallest, b_m=n-1, s_m=0, temp;
    for (i=0; i<n; i++)
        scanf("%d", &number[i]);
    biggest = number[n-1]; // 先将最大值初始化为规定数组最后一位，便于交换和检测；
    smallest = number[0]; //先将最小值初始化为规定中数组第一位，便于交换和检测；
    // 注意：题中要求先交换最大值，再交换最小值；
    for (i=0; i<n; i++)
        if (number[i]>biggest) // 如果扫描数组有数大于最大值；
        {
            biggest = number[i];
            b_m = i; // 存储最大值下标；
        }
    
    if (number[b_m]!=number[n-1]) //如果最后一位不是最大值
    {
        temp = number[b_m];
        number[b_m] = number[n-1];
        number[n-1] = temp;
    } // 进行交换
    
    for (i=0; i<n; i++)
        if (number[i]<smallest) //如果扫描数组有数小于最小值：
        {
            smallest = number[i];
            s_m = i; // 存储最小值下标
        }

    if (number[s_m]!=number[0]) // 如果第一位不是最小值
    {
        temp = number[s_m];
        number[s_m] = number[0];
        number[0] = temp;
    } // 进行交换
    for (i=0; i<n; i++) // 循环输出
        printf("%d ", number[i]); // 每个整数后都要带一个空格；
    return 0;
}