#include <stdio.h>
#include <stdlib.h>

#define arraySize 1024

void ArrayOutput(const double *array, int size);

int main()
{
    double a[arraySize];
    int k, n;

    scanf("%d", &n);
    if (n < 1 || n > arraySize)
    {
        puts("Error!");
        exit(1);
    }

    for (k = 0; k < n; ++k)
    {
        scanf("%lg", &a[k]);
    }

    ArrayOutput(a, n);
    putchar('\n');
    return 0;
}

/* 你提交的代码将被嵌在这里 */

void ArrayOutput(const double *array, int size)
{
    int i;
    for (i=0; i<size; i++)
    {
        printf("%.1lf", array[i]);
        if (i<size-1)
            printf(", ");
    }
}