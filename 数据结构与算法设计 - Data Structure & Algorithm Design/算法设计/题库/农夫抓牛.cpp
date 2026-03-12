/*类型：BFS、队列
 *农夫John和一头逃跑的牛在同一坐标轴上
 *John的初始位置为N(0<N<=100,000),牛的位置为K(0<K<=100,000)
 *假定John在追逐过程中，牛不会移动
 *John有两种追逐方式：1）从位置X移动X-1或者X+1需要一分钟时间；2）一分钟内，可以从位置X移动到位置2*X
 *问，John最少需要多少时间追到牛。
*/

#include<iostream>
#include<queue>
using namespace std;
//完成以下函数定义：

int catchcattle(int N,int K) {
    int flag[100010]={0}, move[3] = {1, -1, 0};
    int times=0;
    
    // 模拟队列方法
    int field[100010], front, rear;
    front = rear = -1;

    field[++rear] = N;
    flag[N] = 1;
    int john, mark=0;

    while (front != rear)
    {
        john = field[++front];
        if (john == K)
            return times;
        move[2] = john;
        for (int i=0; i<3; i++)
        {
            int position = john + move[i];
            if (flag[position] == 0 && m < K+1 && m >= 0)
            {
                field[++rear] = m;
                flag[position] = 1;
            }
        }
        if (john == mark)
        {
            mark = rear;
            times += 1;
        }
    }
    return -1;
    
    /*  STL队列方法
    queue<int> field;

    field.push(N);
    flag[N] == 1;
    int john, mark=N;

    while (!field.empty())
    {
        john = field.front();
        field.pop();
        if (john == K)
            return times;
        move[2] = john;
        for (int i=0; i<3; i++)
        {
            int m = john + move[i];
            if (flag[m] == 0 && m <= K+1 && m >= 0)
            {
                field.push(m);
                flag[m] = 1;
            }
        }
        if (john == mark)
        {
            mark = field.back();
            times++;
        }
    }
	return -1;
    */
}

int main()
{
    int n,k;
    cin>>n>>k;
	cout<<catchcattle(n ,k);
	return 0;
}
