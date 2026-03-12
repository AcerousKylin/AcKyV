// https://vjudge.csgrandeur.cn/problem/CodeForces-255B

#include<bits/stdc++.h>
using namespace std;

int main(void)
{
    string a;
    cin >> a;
    int length = a.size();
    int x = count(a.begin(), a.end(), 'x'), y = count(a.begin(), a.end(), 'y');
    if (y>x)
        for(int i=0; i<y-x; i++)
            cout << "y";
    else
        for(int i=0; i<x-y; i++)
            cout << "x";
    return 0;
}

// 暴力法可用冒泡排序后，找临界位置删除，非常的费劲
// 实际上，最后的结果即x与y两者出现次数更高的一者输出差次数

//count(a.begin(), a.end(), 'y')