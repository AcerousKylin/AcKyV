#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const long long N = 1e8 + 10;

int n;
LL m;
int vote[N]={0};

// 快排写法（本题较慢）
void quick_sort(int l, int r)
{
    if (l >= r)
        return;
    
    int x = vote[l+r+1>>1], i=l-1, j=r+1;
    while (i < j)
    {
        while (vote[++i] < x);
        while (vote[--j] > x);
        if (i < j)  swap(vote[i], vote[j]);
    }

    quick_sort(l, i-1);
    quick_sort(i, r);
}

int main(void)
{
    scanf("%d %lld", &n, &m);

    for (LL i=0; i<m; i++)
        scanf("%d", &vote[i]);

    quick_sort(0, m-1);

    for (LL i=0; i<m; i++)
        printf("%d ", vote[i]);

    return 0;
}

/*
// 桶排序写法（本题较快）
int main(void)
{
    scanf("%d %lld", &n, &m);

    for (int i=0; i<m; i++)
    {
        int temp;
        scanf("%d", &temp);
        // printf("temp = %d\n", temp);
        vote[temp]++;
    }

    for (LL i=1; i<=n; i++)
        for (int j=0; j<vote[i]; j++)
            printf("%d ", i);

    return 0;
}
*/