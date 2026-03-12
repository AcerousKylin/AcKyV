/*
    题号：1209
    n = a + b/c（默认认为除法结果都是小数）
    1.枚举全排列（纯暴力）
        先得到九个数，然后枚举a,b,c三个数的位数
        最后将a,b,c转化成数字，将数字进行验证
        复杂度：全排列n! *  最后得数n * 枚举位数（算）C|8|2 = 91445760，大概4s左右
    2.优化方法
        n是给定的，因此可以看作自变量只有两个：cn = ca + b，自变量为a和c
        根据范围1~10^6可知，因此a最多5位
        先枚举a，再枚举c，最后判断b是否成立。
        每个a的每个结点上还需要重新枚举c（对a减支），在c的每个结点上判断b（对b和c减支）
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 20;

int n, ans=0; // global var ans means how many method we've found as the result
bool used[N], backup[N]; // record the numbers we've used

bool check(int a, int c) // in order to check the equation and count availible methods
{
    int b = c * (n - a); // the tranformation of the origin equation

    if (!b || !c) // var b and var c must not be 0
        return false;

    memcpy(backup, used, sizeof(used)); // because the check function still in recursion, so we can't edit array used
    
    while (b) // get all units of b, until it's 0(waste)
    {
        int x = b % 10; // get the last unit
        b /= 10; // for next unit
        if (!x || backup[x]) // x, which is the number in b, must not be 0
            return false;
        backup[x] = true; // legal, then record it for final judging
    }

    for (int i=1; i<=9; i++)
        if (!backup[i]) // every number must be used
            return false;

    return true;
}

void dfs_c(int u, int a, int c)
{
    if (u > n) // if var a have used all numbers, reject it
        return;
    
    if (check(a, c)) // verify the equation
        ans++;
    
    for (int i=1; i<=9; i++) // enumerate var c
    {
        if (!used[i])
        {
            used[i] = true;
            dfs_c(u+1, a, c*10+i); // directly change the var c in the argument delivery
            used[i] = false; // recover
        }
    }
}

void dfs_a(int u, int a) // var u means how many numbers we've used, var a means current value of var a
{
    if (a >= n) // var a must not be bigger that const n
        return;
    
    if (a) // and var a must not be 0, judge from there should save some time
        dfs_c(u, a, 0); // finally we need var a and var c to calculate var b and verify the equation, so var a function as an argument

    for (int i=1; i<=9; i++) // enumerate var a
    {
        if (!used[i])
        {
            used[i] = true;
            dfs_a(u+1, a*10+i); // directly change the var a in the argument delivery
            used[i] = false; // recover
        }
    }
}

int main(void)
{
    cin >> n;

    dfs_a(0, 0); // no number selected and a is void

    cout << ans << endl; // output, using cin/cout as little data

    return 0;
}