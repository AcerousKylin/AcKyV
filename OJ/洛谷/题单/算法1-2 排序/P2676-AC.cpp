#include<bits/stdc++.h>

using namespace std;

/* 本题思路：
逆序排序后，直接使用最高的奶牛开始叠罗汉，
当高度大于等于b后，无论如何替换最上方的奶牛，
此时奶牛数量一定是最少的
如果在源数据上使用dfs，漫无目的地搜会导致时间复杂度剧增
*/

const long long N = 1e6 + 10;

int n, s;
long long h[N];
long long b, height=0, ans=0;

// 经典快排
void quick_sort(int l, int r)
{
    if (l >= r)
        return;

    int x=h[l+r+1>>1], i=l-1, j=r+1;

    while(i < j)
    {
        while (h[++i] > x);
        while (h[--j] < x);
        if (i < j)  swap(h[i], h[j]);
    }

    quick_sort(l, i-1);
    quick_sort(i, r);
}

int main(void)
{
    scanf("%d %d", &n, &b);
    for (int i=1; i<=n; i++)
        scanf("%d", &h[i]);

    quick_sort(1, n);

    // 利用前缀和
    for (int i=1; i<=n; i++)
    {
        height += h[i];
        ans++;
        if (height>=b)
        {
            printf("%d", ans);
            return 0;
        }
    }
}