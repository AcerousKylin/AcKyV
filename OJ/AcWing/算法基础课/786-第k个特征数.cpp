#include <bits/stdc++.h>

using namespace std;

const long long N = 1e7 + 10;

int n, k;
int num[N];

int quick_choose(int l, int r, int k)
{
    if (l >= r)
        return num[l];
    
    int x = num[ l + r >> 1];
    int i=l-1, j=r+1;
    while(i < j)
    {
        while (num[++i] < x);
        while (num[--j] > x);
        if (i < j)    swap(num[i], num[j]);
    }

    if (k <= j)
        return quick_choose(l, j, k);
    else
        return quick_choose(j+1, r, k);
}

int main(void)
{
    scanf("%d %d", &n, &k);

    for (int i=0; i<n; i++)
        scanf("%d", &num[i]);
    
    // 此处若k可以为0，则使用k作为起始值
    printf("%d", quick_choose(0, n-1, k-1) );
    
    return 0;
}