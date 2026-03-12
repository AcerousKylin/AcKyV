#include <iostream>
#include <string>
using namespace std;

int main(void)
{
    int n, i, sign=0;
    string a;
    cin >> n >> a;
    for (i=0; i<n-1; i++)
    {
        if (a[i]!=a[i+1])
        {
            sign = 1;
            break;
        }
    }
    if (sign)
        cout << "YES" << endl << a[i] << a[i+1] << endl;
    else
        cout << "NO" << endl;
    return 0;
}

// 编译环境选GNU G++20 11.2.0