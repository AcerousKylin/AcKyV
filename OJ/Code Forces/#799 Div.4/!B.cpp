#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int a[2][n];
    int quantity=0;
    for(int i=0; i<n; i++)
    {
        int temp;
        cin >> temp;
        for(int j=0; j<=quantity; j++)
        {
            if (a[0][j] == temp)
            {
                a[1][j]++;
                // cout << "repeat number plused, is " << temp << endl;
                break;
            }
            if ( j == quantity )
            {
                a[0][quantity] = temp;
                a[1][quantity] = 0;
                quantity++;
                // cout << "new number applied, is " << temp << endl;
                break;
            }
        }
    }
    int cnt = 0;
    for (int i=0; i<quantity; i++)
    {
        // cout << "current number is " << a[0][i] << ", which had shown " << a[1][i] << " times" << endl;
        if ( a[1][i]%2==0 )
        {
            cnt++;
            // cout << "number remained founded, is " << a[0][i] << endl;
        }
    }
    int result = (cnt==0)?2:cnt;
    cout << result << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        solve();
    return 0;
}