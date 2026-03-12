/*
    题号：93
    排列在顺序上区别每个元素，而组合不区别，如123全排序有6种，而123本身是123的唯一组合。
    要使得组合结果不重复且按顺序排列，就需要人为限制其顺序。
    由于本题是在n个数中选m个，就根据选中位置去看，然后使得每次后一个位置上的数都比前一个位置上的数小即可（或者大也是可以实现的）
    通过递归得出的树去决定dfs的“参数”（全局变量或形式参数）：
        m个位置->m长度的全局数组；
        当前该枚举的位置->形式参数u；
        最小的枚举出发点->全局变量start（这个机制替代了之前枚举中的判重数组）
    符合字典序；注意排序的极值（方案数），一般取C|n|n/2
    dfs的优化：
        减支，如本题存在的一些不可能的预选方案，可以通过一些手段跳过。
        （注意u和start的初始值，这里是u的初始值为1的数值，后标记初始值为0时的数值修正）
        当我们在选择第u个数时，我们已经选了u-1个数(u)
        还可以选的备选数是n-start+1个，两者之和应该要<m
    还可以通过筛选固定长度的排列型枚举结果来得出排列型枚举的结果。
*/


#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 25; // shall be bigger, unless using 0 as starter of u like the below
int n, m, order=1; // using a global variety
int st[N]; // result

void dfs(int u)
{
    if (u == m) // u == m + 1 if u start with 1
    {
        for (int i=0; i<m; i++)
            printf("%d ", st[i]);
        puts(""); // remember to put an enter
        return;
    }

    for(int i=order; i<=n; i++)
    {
            st[u] = i;
            order = i+1; // be careful that the last number can't be enumerated
            dfs(u+1); // go to the next position

            st[u] = 0; // recover
            order = i+1; // also, because the next position change the variety order
    }
}

int main(void)
{
    cin >> n >> m;
    dfs(0);
    return 0;
}

// or set a argument for dfs instead of using a global variety
// the same data, up one runs 141ms, below one runs 38ms, so it'd better be optimized

/*
const int N = 30; // consider for no boundry issue
int n, m;
int st[N]; // result

void dfs(int u, int start) // start is the biggest number we have chosen
{
    if (u + n - start < m)
        return;
    if (u == m + 1)
    {
        for (int i=1; i<=m; i++)
            printf("%d ", st[i]);
        puts(""); // remember to put an enter
        return;
    }

    for(int i=start; i<=n; i++)
    {
            st[u] = i;
            dfs(u+1, i+1); // go to the next position, and be careful that the last number can't be enumerated
            st[u] = 0; // recover, but actually it will be overwrite, which means it's insignificant and just for completement
    }
}

int main(void)
{
    cin >> n >> m;
    dfs(1, 1);
    return 0;
}

*/