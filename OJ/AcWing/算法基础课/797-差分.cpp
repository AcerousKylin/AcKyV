/*
    前缀与差分是逆运算的关系，差分的前缀和可以变为前缀数组。因此知道了差分，可以用O(n)的时间算出原数组的前缀和
    当我们在前缀数组选取一个闭区间[l, r]，并且将al~ar都加上一个常数C。正常暴力解需要O(n)遍历一遍
    但当我们利用差分数组就可以更快：
        差分是什么：
            对于初始数组a，有数组b，使得b[i]=a[i]-a[i-1]，b即为a的差分数组
            相对地，我们发现，差分数组b的前缀和数组就是a，也就是b1+...+bi=ai
            也就是说，差分和前缀和是逆运算，原数组通过差分后再进行前缀和就可以还原
        那么我们要实现区间内同加的操作时，通过如下推导可知：
            没有加之前              加了之后
            a[i]-a[i-1]=b[i];       (a[i]+C)-a[i-1]=b[i]+C;
            a[i+1]-a[i]=b[i+1];     (a[i+1]+C)-(a[i]+C)=b[i+1];
            ...                     ...
            a[r]-a[r-1]=b[r];       (a[r]+C)-(a[r-1]+C)=b[r];
            a[r+1]-a[r]=b[r+1];     a[r+1]-(a[r]+C)=b[r+1]-C
        在原数组同加后，差分数组的l和r+1处发生了一加一减
        因此，只要我们进行预处理差分，再在差分数组上对更改区间的指定位置进行操作
        最后进行前缀和，就能在还原出先前的数组的同时完成同加
    下面是详细的分布骤代码：
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 100010;
int n, m;
int a[N], b[N];

void Insert(int l, int r, int C)
{
    b[l] += C;
    b[r+1] -= C;
    // as we calculate it, no matter what kind of change
}

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++)
        scanf("%d" ,&a[i]);

    for (int i=1; i<=n; i++)
        Insert(i, i, a[i]);
        // put array a into array b like a finite difference

    while (m--)
    {
        int l, r, C;
        scanf("%d %d %d", &l, &r, &C);
        Insert(l, r, C);
        // then put the changes in
    }

    for (int i=1; i<=n; i++)
        b[i] += b[i-1];
        // and apply prefix sum to recover data
    
    for (int i=1; i<=n; i++)
        printf("%d ", b[i]);
    
    return 0;
}