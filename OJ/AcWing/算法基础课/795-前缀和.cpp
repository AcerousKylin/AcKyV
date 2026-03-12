#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

// cautious about the boundry
const int N = 100010;

int n, m;
int arr[N];

int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++)
    {
        int x;
        scanf("%d", &x);
        arr[i] = arr[i-1] + x; // prefix initializing
    }
    
    for (int i=1; i<=m; i++)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", arr[r]-arr[l-1]);
        // summary from l to r is needed, which is prefixed summary l-1 minus r
    }
    
    return 0;
}