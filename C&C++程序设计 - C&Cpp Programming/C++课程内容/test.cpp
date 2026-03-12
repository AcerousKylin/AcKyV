#include <iostream>
using namespace std;

int x[10], n, count=0;

int Place(int num)
{
    for (int i=1; i<=num; i++)
    {
        if (x[i] == x[num] || abs(i-num) == abs(x[i]-x[num]))
            return 0;
        else
            return 1;
    }
}

void Queen()
{
    for (int i=1; i>=1;)
    {
        x[i]++;
        while (x[i]<=8 && !Place(i))
            x[i]++;
        if (x[i] == 9)
            x[--i] = 0;
        else if (x[i] < 8)
            i += 1;
        else
        {
            count++;
            if (count != n)
                continue;
            else
            {
                for (int i=1; i<=8; i++)
                    cout << x[i];
                cout << endl;
                return;
            }
        }
    }
}

int main()
{
    cin>>n;
    for (int i=0; i<8; i++)
        x[i] = 0;
    Queen();
    return 0;
}
