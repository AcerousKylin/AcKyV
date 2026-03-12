/*类型：动态规划、简单循环
 *给定一个包含正整数的 m×n 网格，（为降低难度m=5,n=3,存储在数组dist[5][3]中。）
 *每次只能向下或者向右移动一步，定义路径长度是路径上经过的整数之和。
 *请找出一条从左上角(位置为(0,0))到位置(k,l)的路径，使得路径长度最大。
 *（注意，是求最长路径！！！）
*/

#include <iostream>
using namespace std;
int main()
{
    int m=5,n=3;
    int a[5][3]={ 8,75,92, 6,65,71, 5,63,7, 5,87,90, 76,7,8 };
    int dist[m][n], path[m][n], i, j, k, l;
    cin>>k>>l;
    dist[0][0] = a[0][0];
    for (i=1; i<m; i++)
        dist[i][0] = dist[i-1][0] + a[i][0];
    for (j=1; j<n; j++)
        dist[0][j] = dist[0][j-1] + a[0][j];
    for (i=1; i<=k; i++)
    {
        for (j=1; j<=l; j++)
        {
            int up=dist[i-1][j], right=dist[i][j-1];
            dist[i][j] = max(up, right)+a[i][j];
        }
    }
    i--; j--;
    while (i>0 && j>0)
    {
        if (dist[i-1][j] > dist[i][j-1])
            path[i--][j] = 1;
        else
            path[i][j--] = 0;
    }
    cout<<dist[k][l];//返回最优值
    return 0;
}
