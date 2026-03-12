#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    int a[n];
    int cnt=0, j=0;
    for(int i=0; i<n; i++)
    {
        int size, direction;
        cin >> size >> direction;
        if (direction)
            a[++j] = size;
        else
        {
            while( size>a[j] && j>0 )
            {
                j--;
                cnt++;
            }
            if (j!=0)
                cnt++;
        }
    }
    cout << n-cnt << endl;
    return 0;
}