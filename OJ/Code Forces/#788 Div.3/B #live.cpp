#include<iostream>
using namespace std;

const int N = 501000;
int n, k;
bool mark[30];
char s[N], t[10];

void solve()
{
    scanf("%d", &n);
    scanf("%s", s);
    scanf("%d", &k);
    for (int i=0; i<26; i++)
    {
        mark[i] = false;
    }
    for (int i=0; i<k; i++)
    {
        scanf("%s", t);
        mark[t[0]-'a'] = 1;
    }

    int len=0, ans=0;
    for (int i=0; i<n; i++)
    {
        if (mark[s[i]-'a'])
            ans = max(ans, len), len=1;
        else
            len++;
    }
    printf("%d\n", ans);
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