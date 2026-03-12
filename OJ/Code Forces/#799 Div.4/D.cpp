#include<bits/stdc++.h>
using namespace std;

void solution()
{
    int h, m;
    char temp;
    cin >> h >> temp >> m;
    //cout << "origin time is "<< h << ":" << m << endl;
    int period;
    cin >> period;
    int hta = period / 60;
    int mta = period % 60;
    int th=-1, tm=-1, cnt=0;
    for (int i=1; th!=h || tm!=m; i++)
    {
        th = h + hta * i;
        tm = m + mta * i;
        th += tm / 60;
        th %= 24;
        tm %= 60;
        //cout << "now is "<< th << ":" << tm << endl;
        if ( th%10==tm/10 && th/10==tm%10 )
            cnt++;
    }
    cout << cnt << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        solution();
    return 0;
}