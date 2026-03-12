/*
    输出字典序排序的n的全排列
    很显然，这题的复杂度大概在n*n!了，多半使用dfs（9!=326880）
    字典序：两个序列的每位进行比较，相同位相等，直到两位其中一位更大，则认为哪一序列字典序更大，若一方不存在这一位了，则这一序列更小
        如n=3，会有6种。递归还是先想顺序：1.依次枚举每个数字放在哪个位置（按照数字的顺序）。2.依次枚举每个位置放哪个数字（按照位次的顺序）。
        这里用第二种顺序。递归树的每一层都确定一个位置上的数，如果所有小二叉树的左树所填数字都比右树小，那么最后的叶节点从左到右正好是字典序。
        一般只要按照正常的顺序去写，一般字典序都是最小的。
    用长度为n的数组去记录当前位置的状态，还要存一下数字有没有被用过
*/  

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10; // watch out for data boundry

int n;
int state[N]; // record state of each position, 0=void, 1~n=filled number, all set to 0 automatically as default
bool used[N]; // record used number, true=used, false=availible

void dfs(int u)
{
    if (u > n) // reach the boundry(u==n while u started with 0)
    {
        for (int i=1; i<=n; i++) // print the whole branch
            printf("%d ", state[i]);
            puts(""); // another method to print an enter
        return;
    }
        
    for (int i=1; i<=n; i++)
        if (!used[i]) // find the first availible number in order
        {
            state[u] = i; // fill the current position
            used[i] = true; // upgrade the state to used
            dfs(u+1);

            // recover to the last state
            state[u] = 0;
            used[i] = false;
        }
}

int main(void)
{
    scanf("%d", &n);
    dfs(1); // start line is 1
    return 0;
}