#include <bits/stdc++.h>

using namespace std;

const int N =1e6 + 10;

int n, num[N], ans[N];

long long merge_sort(int l, int r)
{
    if (l >= r)
        return 0;

    int mid = l+r>>1;
    // 逆序对的数量需要注意，建议使用long long
    long long cnt = merge_sort(l, mid) + merge_sort(mid+1, r);

    int k=0, i=l, j=mid+1;
    while(i <= mid && j <= r)
        if (num[i] <= num[j])
            ans[k++] = num[i++];
        else
        {
            cnt += mid - i + 1;
            ans[k++] = num[j++];
        }

    while (i <= mid)
        ans[k++] = num[i++];
    while (j <= r)
        ans[k++] = num[j++];

    for (i=l, j=0; i<=r; i++, j++)
        num[i] = ans[j];

    return cnt;
}

int main(void)
{
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);

    printf("%lld", merge_sort(0, n-1));
    
    return 0;
}