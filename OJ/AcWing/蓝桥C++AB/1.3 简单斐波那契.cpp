/*
    题号：717
    递推写斐波那契：f(1)=0，f(2)=1，f(n)=f(n-1)+f(n-2)(n>2).
    递归是将一个问题分解成若干同种子问题，递推就是反过来，解决小问题后去推出这个问题。
    用数组
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    
    // use an array could do
    int f[47];
    f[1] = 0, f[2] = 1;

    for (int i=3; i<=n; i++)
        f[i] = f[i-1] + f[i-2];
    for (int i=1; i<=n; i++)
        cout << f[i] << ' ';

    // or just use two variety and upgrade them continouously for saving space
    /*
        int a = 0, b = 1;
        for (int i=1; i<=n; i++)
        {
            cout << a << ' '; // output the very first number remain, easy for counting
            int fn = a + b; // set a fn in the end of the "array"
            a = b; b = fn; // scrolling them(that is a rudiment of scrolling array)
        }
    */

    cout << endl; // insignificant

    return 0;
}
