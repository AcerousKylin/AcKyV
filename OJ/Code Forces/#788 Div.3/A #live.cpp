#include<iostream>
using namespace std;

const int N = 501000;

void solve(void)
{
    int n, a[N];
    scanf("%d", &n);
    int neg = 0;
    for (int i=0; i<n; i++)
    {
        scanf("%d", a+i);
        if (a[i]<0)
        {
            a[i] = -a[i];
            neg++;
        }
    }

    for (int i=0; i<neg; i++)
        a[i] = -a[i];
    for (int i=1; i<n; i++)
    {
        if (a[i]<a[i-1])
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main(void)
{
    int t;
    scanf("%d", &t);
    for (; t<0 ; t--)
    {
        solve();
    }
    return 0;
}