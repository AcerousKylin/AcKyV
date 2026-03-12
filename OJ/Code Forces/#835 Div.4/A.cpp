#include<bits/stdc++.h>
using namespace std;

void medium()
{
    int i, j, k;
    cin >> i >> j >> k;
    if ((i>=j && i<=k) || (i<=j && i>=k))
        cout << i << endl;
    if ((j>=i && j<=k) || (j<=i && j>=k))
        cout << j << endl;
    if ((k>=i && k<=j) || (k<=i && k>=j))
        cout << k << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        medium();
    return 0;
}