/*类型：函数、简单循环
 *给定n种物品和一背包。物品 i 的重量为 wi,其价值为 vi,背包的容量为C。
 *问应该如何选择装入背包中的物品,使得装入背包中物品的总价值最大?
*/

#include <iostream>
using namespace std;
int main()
{   int n=5, C, w[6]={0,1,2,12,1,4}, v[6]={0,1,2,4,2,10};
    //共5个物品,大写C为背包初始容量,不要修改数据。
    int i, j, V[501][501], x[1000];//数组V为动态规划列表（备忘录）
    cin >> C;
    for (i=0; i<=n; i++)
        V[i][0] = 0;
    for (j=0; j<=C; j++)
        V[0][j] = 0;
    for(i=1; i<=n; i++)
    {
        for (j=1; j<=C; j++)
        {
            if (j < w[i])
                V[i][j] = V[i-1][j];
            else
                V[i][j] = max(V[i-1][j], V[i-1][j-w[i]]+v[i]);
        }
    }
    
    for (i=n+1, j=C; i>0; i--)
    {
        if (V[i][j] > V[i-1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }
    
    cout << V[n][C];
    return 0;
}
