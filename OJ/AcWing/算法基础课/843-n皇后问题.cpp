#include<iostream>
using namespace std;

const int N = 10;

int n;
// char board[N][N];
int row[N];
bool col[N], diag[N], bdiag[N];

void dfs( int u )
{
    if ( u == n )
    {
        /*
        for ( int i=0; i<n; i++)
            cout << board[i] << endl;
        cout << endl;
        */
        for (int i=0 ; i<n; i++)
        {
            for (int j=0; j<n; j++)
            {
                if ( row[i] == j )
                    printf("Q");
                else
                    printf(".");
            }
            printf("\n");
        }
        printf("\n");
        return;
    }
    
    for (int i=0 ; i<n; i++)
    {
        if ( !col[i] && !diag[ u + i ] && !bdiag[ n - u + i ] )
        {
            // board[u][i] = 'Q';
            row[u] = i;
            
            col[i] = diag[ u + i ] = bdiag[ n - u + i ] = true;
            dfs( u + 1 );
            col[i] = diag[ u + i ] = bdiag[ n - u + i ] = false;
            
            // board[u][i] = '.';
            row[u] = i;
        }
    }
}

int main(void)
{
    cin >> n;
    
    /*
    for (int i=0; i<n; i++)
        for (int j=0 ; j<n; j++)
            board[i][j] = '.';
    */
    
    dfs(0);
    
    return 0;
}