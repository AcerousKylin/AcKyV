#include <iostream>
using namespace std;
int main()
{
    int r[10000]={0}, n, m;
    int counter, i = -1, num = 0;
    cin >> n >> m;
    counter = 0;
    for (int i=0; i<n; i++)
    {
        // cout << "i is " << i << "." << endl;
        if (num == n-1)
            break;
        if (r[i] == 1);
            // cout << i << " is passed." << endl;
        else
        {
            counter++;
            if (counter == m)
            {
                r[i] = 1;
                // cout << i+1 << " is out." << endl;
                counter = 0;
                num++;
            }
        }
        if (i == n-1)
            i = -1;
    }
    for (i = 0; i < n; i++)
        if (r[i] == 0)   //返回编号
            cout << i+1;
    return 0;
}
