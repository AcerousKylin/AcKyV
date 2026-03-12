#include<bits/stdc++.h>
using namespace std;
#pragma GCC optimize(2)

const int N = 1e6;
int a[N]={0};

inline void read(int &x)
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

inline void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
        write(x / 10);
    putchar(x % 10 + '0');
}

void Advantagedlize()
{
    int n;
    cin >> n;

    int pmax=0, smax=0;
    for (int i=1; i<=n; i++)
    {
        read(a[i]);
        if (a[i] > a[pmax])
        {
            smax = pmax;
            pmax = i;
        }
        else if(a[i] > a[smax])
            smax = i;
    }
    
    for (int i=1; i<=n; i++)
    {
        if (i != pmax)
            write(a[i] - a[pmax]);
        else
            write(a[i] - a[smax]);
        putchar(' ');
    }
    putchar('\n');
}

int main(void)
{
    int n;
    read(n);
    for (int i=0; i<n; i++)
        Advantagedlize();
    return 0;
}