#include<iostream>
using namespace std;

const int N = 10;

int n;
int path[N];
bool num[N];

void dfs(int u)
{
    if (u == n)
    {
        for(int i = 0; i < n; i++)
        {
            printf("%d", path[i]);
            i==n-1?printf("\n"):printf(" ");
        }
        return;
    }
    
    for(int i=1; i<=n; i++)
    {
        if (!num[i])
        {
            path[u] = i;
            num[i] = true;
            dfs( u + 1 );
            num[i] = false;
        }
    }
}

int main(void)
{
    cin >> n;
    
    dfs(0);
    
    return 0;
}