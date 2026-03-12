/*
    题号：92
    对于n个数选取任意个数的所有情况有2^n种可能
    每个数都有选和不选两种可能，用二叉树去表示，每个叶节点就是一种可能。
        2^1 ~ 2^10
        2^20 = 10^6
        2^16 = 65536
        2^15 = 32768
        2^63 = 10^18
    本题从范围和复杂度来看，最多是15*2^15。而选择的方案一共有2^n个，每个方案长度算作n，因此复杂度也就是15*2^15了。
    我们这回用递归去写，递归最重要的是顺序：1~n依次考虑每个数选或不选。
        如n=3，先看位置1选或不选（2、3为空），位置2选或不选（3为空），位置3选或不选
    那么每个位置的状态需要记录下来，选用一个长度为n的数组，也可以使用位运算进行存储（更快）
*/

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 16; // if u start with 1, please watch out the length

int n;
int st[N]; // record statement of each position, 0=void, 1=selected, 2=unselected, all set to 0 as default
            // also, we can use a single number to achieve it by calculation bit by bit

void dfs (int u) // u is current position waiting
{
    if (u > n) // reach the boundry when u>n (u==n while u start with 0)
    {
        for (int i=1; i<=n; i++) // check each posotion if they were considered (i==0 & i<n while u started with 0)
            if (st[i] == 1) // if selected, output it
                printf("%d ", i);
            printf("\n"); // remember to put an enter
        return;
    }
    // branches
    st[u] = 2; // unselected, then next position
    dfs(u+1);
    st[u] = 0; // recover the origin state

    st[u] = 1; // selected, then next position
    dfs(u+1);
    st[u] = 0; // recover the origin state
}

int main(void)
{
    cin >> n;
    dfs(1); // input start line, could be 0
    return 0;
}