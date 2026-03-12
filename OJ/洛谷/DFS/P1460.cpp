#include<bits/stdc++.h>
using namespace std;

/*

const int N = 50;

int v=N, g=N;
int need[N]={0};

int ftlz[N][N]={0};
int feed[N]={0};
int code[N]={0};

bool scale[N]={false};
bool b=false;

bool fill_in(int uses)
{
    for(int i=1; i<=v; i++)
    {
        int sum = 0;
        for(int j=1; j<=uses; j++)
            sum += ftlz[code[j]][i];
        if (sum < need[i])
        {
            printf("Wrong Fillers!\n");
            return false;
        }
    }
    return true;
}

void main_dfs(int uses, int last)
{
    if (fill_in(uses))
    {
        printf("Gotcha!\n");
        printf("%d", uses);
        for(int i=1; i<=uses; i++)
            printf(" %d", code[i]);
        exit(0)
    }
    
    for(int i=last; i<=g; i++)
    {
        if (!scale[i])
        {
            scale[i] = true;

            if (last==g)
            {
                printf("Now we are using %d kinds of f\n", uses+1);
                dfs(uses+1, 1);
            }
            if (last!=g)
                dfs(uses, i+1);

            for(int j=1; j<=v; j++)
                feed[j] -= ftlz[i][j];
            scale[i] = false;
            printf("No, take f%d\n", code[uses]);
        }
    }
}

void floor_dfs(const int u, int uses, int last)
{
    if (uses==0 || last>g || !scale[i] || fill_in(u))
        return;
    for (int i=1; i<=g; i++)
    {
        for (int j=1; j<=v; j++)
            feed[j] += ftlz[i][j];
        code[uses] = i;
        scale[i] = true;
        
        floor_dfs(u, uses-1; last+1);

        for (int j=1; j<=v; j++)
            feed[j] -= ftlz[i][j];
        scale[i] = true;
    }
}

int main(void)
{
    cin >> v;
    for (int i=1; i<=v; i++)
        cin >> need[i];

    cin >> g;
    for (int i=1; i<=g; i++)
        for (int j=1; j<=v; j++)
            cin >> ftlz[i][j];

    dfs(1, 1);

    return 0;
}

*/

// 迭代加深写法

const int N = 50;

int v, g;
int need[N], ftlz[N][N], feed[N];
bool ctnr[N];

void dfs(int last, int used, int uses)
{
    if (used==uses)
    {
        for (int i=1; i<=v; i++)
            if (feed[i] < need[i])
                return;

        cout << uses << ' ';
        for (int i=1; i<=g; i++)
            if (ctnr[i])
                cout << i << ' ';
        exit(0);
    }

    if (g-last < uses-used)
        return;
    
    for (int i=last+1; i<=g; i++)
    {
        ctnr[i] = true;
        for (int j=1; j<=v; j++)
            feed[j] += ftlz[i][j];
        
        dfs(i, used+1, uses);

        for (int j=1; j<=v; j++)
            feed[j] -= ftlz[i][j];
        ctnr[i] = false;
    }
}

int main(void)
{
    cin >> v;
    for (int i=1; i<=v; i++)
        cin >> need[i];

    cin >> g;
    for (int i=1; i<=g; i++)
        for (int j=1; j<=v; j++)
            cin >> ftlz[i][j];

    for(int i=1; i<=g; i++)
        dfs(0, 0, i);
    
    return 0;
}