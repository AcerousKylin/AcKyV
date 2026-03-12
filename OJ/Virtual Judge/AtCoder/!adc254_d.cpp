// attribute from "tjrac6021203579"

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int main (void)
{
    ll n;
    cin >> n;
    ll ans=0;
    for (int i=1; i*i<=n; i++)
        for (int j=1; j*j<=n; j++)
            if(__gcd(i,j)==1)
                ans += n/max(i*i, j*j);
    cout<<ans<<endl;
    return 0;
}



/*
int Con_pair(int const n, int number)
{
    if (number==1)
        return 1;
    if (number>1)
    {
        int count=0;
        int result=number*number;
        for (int i=1; i<=n; i++)
        {
            if (result % i == 0 && result / i <= n)
            {
                count++;
                //cout<<"i="<<i<<", j="<<result/i<<endl;
            }
        }
        return count + Con_pair(n, number-1);
    }
}

int main(void)
{
    int n;
    cin >> n;
    cout << Con_pair(n, n) << endl;
    return 0;
}
*/