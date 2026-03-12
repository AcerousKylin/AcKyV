#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 10;

void solve()
{
    char num[N] = {' '};
    int length;
    char digit;
    scanf("%d %c", &length, &digit);
    getchar();
    int flag=1;
    for (int i=0; i<length; i++)
    {
        char temp = getchar();
        if (flag && digit > temp)
        {
            num[i++] = digit;
            num[i] = temp;
            length++;
            flag = 0;
        }
        else
            num[i] = temp;
    }
    if (flag)
        num[length] = digit;
    printf("%s\n", num);
}

int main(void)
{
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++)
        solve();
    return 0;
}

/*
#include <string>

using ll = long long;
int main()
{
    ll t;
    cin >> t;
 
    while (t--)
    {
        ll n; 
        char d;
        string s;
        cin >> n >> d >> s;
 
        ll Count = 0;
        while (true)
        {
            if (s[Count] < d)
                break;
            else
                Count++;
        }
 
        for (ll j = 0; j < Count; j++)
            cout << s[j];
        cout << d;
        for (ll j = Count; j < n; j++)
            cout << s[j];
        cout << endl;
    }
 
    return 0;
}
*/