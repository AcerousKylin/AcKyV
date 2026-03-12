#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
bool ran[N]={false};

int main(void)
{
    scanf("%d", &n);
    
    int cnt = n;
    for (int i=0; i<n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (ran[temp])
            cnt--;
        ran[temp] = true;
    }

    printf("%d\n", cnt);

    int j=1;
    while (cnt > 0)
    {
        if (ran[j++])
        {
            cnt--;
            printf("%d ", j-1);
        }
    }
    return 0;
}