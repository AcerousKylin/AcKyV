// 采用贪心+标号法：
// 1.把顶点分为未着色集（也称未标号集）和已着色集（也称已标号集），初始所有顶点属于未着色集，着颜色0，则非0为已着色，初始时已着色集为空集。
// 2.在符合约束条件的情况下，用同一种颜色编号给尽量多的未着色顶点着色，将其加入已着色顶点集合。
// 3.如果第2步中的颜色无法把未标号集中的所有顶点加入已标号集，则启用新颜色编号后，重复第2步直至未标号集为空，即所有顶点都加入到已标号集，算法结束。

#include <iostream>
using namespace std;
int ColorGraph(int arc[100][100], int n, int color[ ]);
int main( )
{
    int arc[100][100] = {{0,1,0,0,0},{1,0,1,1,0},{0,1,0,0,1},{0,1,0,0,1},{0,0,1,1,0}};
    int i, n = 5, color[n]={0},m;
    m=ColorGraph(arc, n, color);
    cout<<"需要颜色数为："<<m<<"着色情况为："<<endl;
    for (i = 0; i < n; i++)
        cout<< color[i]<<" ";
}
int ColorGraph(int arc[100][100], int n, int color[ ])
{
    int i, j, k = 0, flag = 1;
    while (flag == 1)
    {
        k++;
        flag = 0; //取下一种颜色
        for (i = 0; i < n; i++)
        {
            if (color[i] != 0) continue; //顶点i已着色
            color[i] = k; //顶点i着颜色k
            for (j = 0; j < n; j++)
                if (arc[i][j] == 1 && color[i] == color[j]) break;
            if (j < n) //发生冲突，取消涂色
            {
                color[i] = 0;
                flag = 1;
            }
        }
    }
    return k;
}