#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int a, count=0;
    cin >> a ;
    for (int i=0; i<3; i++)
    {
        int p;
        cin >> p;
        if (p>a)
            count++;
    }
    cout << count << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        solve();
    return 0;
}