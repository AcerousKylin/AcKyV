#include<bits/stdc++.h>
using namespace std;

void solution()
{
    char a;
    int x, y, line=0, temp1=0, temp2=0;
    for (int i=1; i<=8; i++)
    {
        for (int j=1; j<=8; j++)
        {
            cin >> a;
            if ( a == '#' && temp1 == 0)
            {
                temp1 = j;
                // cout << "found temp1 is "<< temp1 << endl;
                continue;
            }
            if ( a == '#' && temp2 == 0)
            {
                temp2 = j;
                // cout << "found temp2 is "<< temp2 << endl;
            }
        }
        if (temp1==0 || temp2 == 0)
        {
            temp1 = temp2 = 0;
            // cout << "temp1 or temp2 no found" << endl;
            continue;
        }
        if (line==0)
            line = i;
    }
    // cout << "board scan finished, ";
    // cout << "temp1 is "<< temp1 << ", temp2 is " << temp2;
    // cout << ", and line is "<< line << endl;
    x = (temp1 + temp2) / 2;
    y = (temp2 - temp1) / 2 + line;
    cout << y << " " << x << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
        solution();
    return 0;
}