#include<bits/stdc++.h>
using namespace std;

const int N = 1e6;
typedef long long ll;
ll a[N];

inline void read(ll &x)
{
    x = 0;
    short flag = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            flag = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        x = (x << 3) + (x << 1) + (c ^ 48);
        c = getchar();
    }
    x *= flag;
}

void valley()
{
    int n, flag=0, judge=0;
    cin >> n;

    a[0] = a[n+1] = 1e9+1;
    for (int i=1; i<=n; i++)
        read(a[i]);
    
    for (int i=1; i<=n; i++)
    {
        if (a[i] < a[i-1])
        {
            for (int j=i; j<=n; j++)
            {
                if (a[j] > a[j+1])
                    break;
                if (a[j] < a[j+1])
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
            {
                flag = 0;
                judge++;
            }
        }
    }

    if (judge==1)
    {
        putchar('Y');
        putchar('E');
        putchar('S');
        putchar('\n');
    }
    else
    {
        putchar('N');
        putchar('O');
        putchar('\n');
    }
}

int main(void)
{
    ll n;
    read(n);
    for (int i=0; i<n; i++)
        valley();
    return 0;
}