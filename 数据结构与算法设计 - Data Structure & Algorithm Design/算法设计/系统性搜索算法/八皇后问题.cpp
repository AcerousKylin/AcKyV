#include <iostream>
#include <cmath>
using namespace std;

int x[10], n, count=0;

int Place(int i)
{
    for (int j=0; j<i; j++)
        if (x[i] == x[j] || abs(i-j) == abs(x[i]-x[j]))
            return 0;
    return 1;
}

void Queen()
{
    for (int i=0; i>=0;)
    {
        x[i]++;
        while (x[i] < 8 && Place(i) == 0)
            x[i]++;
        if (x[i] == 8)
            x[i--] = -1;
        else if (i < 7)
            i += 1;
        else
        {
            count++;
            if (count == n)
            {
                for (int j=0; j<8; j++)
                    cout << x[j]+1;
                cout << endl;
                return;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<8; i++)
        x[i] = -1;
    Queen();
    return 0;
}
