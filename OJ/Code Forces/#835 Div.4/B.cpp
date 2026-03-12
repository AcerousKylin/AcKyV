#include<bits/stdc++.h>
using namespace std;

const int A = 'a' - 1;

void alphabet_size(int n)
{
    int max = 'a';
    for (int i=0; i<n; i++)
    {
        char temp;
        cin >> temp;
        if (temp > max)
            max = temp;
    }
    cout << max-A << endl;
}

int main(void)
{
    int n;
    cin >> n;
    for (int i=0; i<n; i++)
    {
        int a;
        cin >> a;
        alphabet_size(a);
    }
    return 0;
}