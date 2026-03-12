#include <stdio.h>

#define arraySize 1024

void RealSwap(double *x, double *y); // 交换两个实数的值
void ArrayInput(double *array, int size); // 输入数组
void ArrayOutput(const double *array, int size); // 输出数组
void ArraySort(double *array, int size);

int main()
{
    double a[arraySize];
    int n;

    scanf("%d", &n);
    if (n < 1 || n > arraySize)
    {
        puts("Error!");
        exit(1);
    }

    ArrayInput(a, n);
    ArraySort(a, n);
    ArrayOutput(a, n);
    putchar('\n');

    return 0;
}

......

/* 你提交的代码将被嵌在这里 */

void ArraySort(double *array, int size)
{
    int i, j;
    for (i=0; i<size; i++)
    {
        for (j=i; j<size; j++)
        {
            if (array[j]<array[i])
            {
                RealSwap(array+i, array+j);
            }
        }
    }
}