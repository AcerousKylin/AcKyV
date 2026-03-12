#include<iostream>
#include<queue>
#include<Windows.h>
using namespace std;
//完成以下函数定义：

// STL队列写法（未完）
int catchcattle(int N,int K) {
    int flag[100010]={0}, move[3] = {1, -1, 0};
    int times=0;
    queue<int> field;

    field.push(N);
    flag[N] == 1;
    int john, mark=N;

    while (!field.empty())
    {
        john = field.front();
        // cout << "John's at " << john << endl;
        field.pop();
        if (john == K)
            return times;
        move[2] = john;
        for (int i=0; i<3; i++)
        {
            int m = john + move[i];
            if (flag[m] == 0 && m <= K+1 && m >= 0)
            {
                // cout << "John go find " << m << endl;
                field.push(m);
                flag[m] = 1;
            }
        }
        cout << "John just wanted to go "<< field.back() << " and next step should be " << mark << endl;
        if (john == mark)
        {
            // cout << "John take a step forward" << endl;
            mark = field.back();
            times++;
        }
        // Sleep(500);
    }
	return -1;
}

int main()
{
    int n,k;
    cin>>n>>k;
	cout<<catchcattle(n ,k);
	return 0;
}
