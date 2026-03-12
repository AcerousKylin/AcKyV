#include<bits/stdc++.h>
using namespace std;

#pragma GCC optimize(2)

// 整形数据快读(short和long long)
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

/*

char *p1, *p2, buf[100000]
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin), p1==p2)?EOF:*p1)

int read()
{
    int x=0, f=1;
    char ch=nc();
    while(ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = nc();
    }
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = nc();
    return x*f;
}
*/

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

int main(void)
{
    int a;
    read(a);
    write(a);
}