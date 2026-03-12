#include<iostream>

using namespace std;

const int N = 1e6 + 10;

int num[N];
int n;

void quick_sort(int num[], int l ,int r)
{
    if (l>=r)   // 判断边界
        return;
    
    /* x使用左边界值
    int x=num[l], i=l-1, j=r+1;
    while (i<j)
    {
        do i++;     while (num[i]<x);
        do j--;     while (num[j]>x);
        if (i<j)    swap(num[i], num[j]);
    }

    quick_sort(num, l, j);
    quick_sort(num, j+1, r);

    当x取右边界值时，以两个数为例：
    移动i&j后，其中一个递归存在(num[], 0, 1)，导致死循环
    下方类似
    */

    // x使用右边界值
    /*
    int x=num[r], i=l-1, j=r+1;A
    while (i<j)
    {
        do i++;     while (num[i]<x);
        do j--;     while (num[j]>x);
        if (i<j)    swap(num[i], num[j]);
    }

    quick_sort(num, l, i-1);
    quick_sort(num, i, r);
    */
    
    // x使用中间值
    int x=num[(l+r+1)/2], i=l-1, j=r+1;
    while (i<j)
    {
        do i++;     while (num[i]<x);
        do j--;     while (num[j]>x);
        if (i<j)    swap(num[i], num[j]);
    }

    quick_sort(num, l, i-1);
    quick_sort(num, i, r);
    // 这里上方两种写法均可
}

int main(void)
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    quick_sort(num, 0, n-1);

    for (int i=0; i<n; i++)
        printf("%d ", num[i]);

    return 0;
}