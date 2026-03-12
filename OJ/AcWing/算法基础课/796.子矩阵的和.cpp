#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1010;

int main(void)
{
    int matrix[N][N];
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);

    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            int x;
            scanf("%d", &x);
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1] - matrix[i-1][j-1] + x;
        }
    }
/*
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
            printf("%d ", matrix[i][j]);
        puts("");
    }
*/
    while (q--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        int result = matrix[x2][y2] - matrix[x1-1][y2] - matrix[x2][y1-1] + matrix[x1-1][y1-1];
        printf("%d\n", result);
    }

    return 0;
}