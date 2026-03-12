#include<bits/stdc++.h>
using namespace std;

inline int QuickRead()
{
    int x=0;    bool flag=1;    char ch=getchar();
    while (ch <'0'||ch >'9')
    {
        if(ch=='-')
            flag = 0;
        ch = getchar();
    }
    while (ch>='0'&&ch<='9')
    {
        x = (x<<1) + (x<<3)+ch-'0';
        ch = getchar();
    }
    if (flag)
        return x;
    return ~(x-1);
}

const int N=150;

int m, n, cnt=0;

bool matrix[N][N]={false};

//布尔矩阵周围设置边界
void set_boundry(void)
{
    for (int i=0; i<=m+1; i++)
        matrix[0][i] = matrix[n+1][i] = true;
    for (int i=1; i<=n; i++)
        matrix[i][0] = matrix[i][m+1] = true;
}

void dfs(int l_r, int l_c)
{
    if (l_r>m && l_c>n)
    {
        printf("%d\n", cnt);
        return;
    }
    if (!matrix[l_r][l_c])
        if (matrix[l_r]  [l_c-1]
        && matrix[l_r]  [l_c+1]
        && matrix[l_r-1][l_c]
        && matrix[l_r+1][l_c])
            cnt++;
    if (l_r>m)
        dfs(1, l_c+1);
    dfs(l_r+1, l_c);
}

int main(void)
{
    n = QuickRead();
    m = QuickRead();
    printf("m=%d, n=%d\n", n, m);
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            char temp;
            temp = getchar();
            if (temp!='0')
                matrix[i][j] = true;
        }
        getchar();
    }

    dfs(1, 1);

    return 0;
}