#include <iostream>
using namespace std;

int main(void)
{
    int r[15], low=0, high=14, mid, i, j, k;
    for (i=0; i<15; i++)
        r[i] = i*10;
    cin >> k;//上面的代码不能修改
    //请把你的代码写在下面循环里：
    while (low <= high)
    {
        int equal=0;
        mid = (low + high + 1) / 2;
        if (k < r[mid])
            high = mid - 1;
        if (k > r[mid])
            low = mid + 1;
        if (k == r[mid])
            equal = 1;
        
        if (equal)
        {
            for (i=0; i<15; i++)
            {
                if (i == mid)
                    cout << "!";
                else
                    cout << "X";
            }
            break;
        }
            
        else
        {
            for (i=0; i<low; i++)
            cout << "X";
            for (i=low; i<=high; i++)
                cout << "?";
            for (i=high+1; i<15; i++)
                cout << "X";
        }
        cout << endl;
    }
    return 0;
}
