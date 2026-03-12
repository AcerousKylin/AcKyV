#include <bits/stdc++.h>

using namespace std;

const int N =1e6 + 10;

int n, num[N], ans[N];

void merge_sort(int num[], int l, int r)
{
    // 区间内没有数，不需要排序，返回
    if (l >= r)
        return;

    // 取中间值
    int mid = (l+r)/2;

    // 递归排序两边
    merge_sort(num, l, mid);
    merge_sort(num, mid+1, r);

    // 排序,i是左区间起点，j是右区间起点
    int k=0, i=l, j=mid+1;
    // 双指针比较，将较小数依次输入临时数组
    while(i <= mid && j <= r)
        if (num[i] <= num[j])
            ans[k++] = num[i++];
        else
            ans[k++] = num[j++];

    // 当两个区间中的一个提前扫描完毕，将另一个直接接入
    while (i <= mid)
        ans[k++] = num[i++];
    while (j <= r)
        ans[k++] = num[j++];

    // 再将排好序的临时数组传回目标数组
    for (i=l, j=0; i<=r; i++, j++)
        num[i] = ans[j];
}

int main(void)
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    // 边界是下标，也可改为1~n
    merge_sort(num, 0, n-1);

    for (int i=0; i<n; i++)
        printf("%d ", num[i]);
    
    return 0;
}