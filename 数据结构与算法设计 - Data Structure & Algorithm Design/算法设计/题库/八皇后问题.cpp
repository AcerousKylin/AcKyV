/*类型：函数、简单循环
 *在8×8格的国际象棋上摆放8个皇后，使其不能互相攻击
 *即任意两个皇后都不能处于同一行、同一列或同一斜线上。
 *对于某个满足满足要求的八皇后的摆放方法，定义一个皇后串X与之对应
 *即X=X1X2X3X4X5X6X7X8，其中Xi(1<=Xi<=8)为相应摆法中第i(1<=Xi<=8)行皇后所处的列数。
 *有人用图论的方法解出92种结果，本题要求采用DFS算法求出第n个皇后串。
 *皇后串的比较是这样的：皇后串X在皇后串Y之前，当且仅当将X视为整数时比Y小。
 *1<=n<=92
*/

#include <iostream>
#include <cmath>
using namespace std;

// x是解向量，x[i]的值代表第i个皇后在第i行放置的列数位置。
int x[10], n, count=0;

// 检测皇后是否可以放置在i位置
int Place(int i)
{
    for (int j=0; j<i; j++)
        if (x[i] == x[j] || abs(i-j) == abs(x[i]-x[j])) // 如果有两个皇后在同一列或者在同一斜线上
            return 0; // 放置失败
    return 1; // 放置成功
}

void Queen()
{
    for (int i=0; i>=0;)
    {
        x[i]++; // 试探第i的个皇后能否放在各个位置
        while (x[i] < 8 && Place(i) == 0) // 边界限制和放置检测
            x[i]++;
        if (x[i] == 8) // 这个分支的解向量算到头也没能找出正确解
            x[i--] = -1; // 回溯到上一个皇后的位置，重新求解向量
        else if (i < 7) // 如果没算完完整的解向量，算下一个皇后的位置
            i += 1;
        else // 算出了正确的解向量
        {
            count++; // 记录合法解的数量
            if (count == n) // 达到要求数量
            {
                for (int j=0; j<8; j++)
                    cout << x[j]+1; // 输出
                cout << endl;
                return;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i=0; i<8; i++)
        x[i] = -1;
    Queen();
    return 0;
}
