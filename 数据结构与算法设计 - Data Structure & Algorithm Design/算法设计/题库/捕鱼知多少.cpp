/*蛮力+递推法、循环+分支
 *n个人合伙夜间捕鱼，上岸时都疲惫不堪，各自在湖边的树丛中找地方睡觉了。
 *清晨，第一个人醒来，将鱼分成 n 份，把多余的一条扔回湖中，拿自己的一份回家了；
 *第二个人醒来，也将鱼分成 n 份，扔掉多余的一条鱼，拿自己的一份回家了；
 *接着，其余人依次醒来，也都按同样的办法分鱼。问：n 个人至少共捕到多少条鱼？
*/

#include <iostream>
using namespace std;

int main()
{   
    int fish[100],i, n,flag = 0;
    cin>>n;
    fish[0] = 1;    //下面的循环从鱼数n+1开始正推和枚举，请完成代码：
    while (!flag)
    {
        fish[0] += n;
        for (i=1; i<n; i++)
        {
            fish[i] = (fish[i-1] - 1) / n * (n-1);
            if (fish[i] % n != 1)
                break;
        }
        if (i == n)
            flag = 1;
    }
    cout << fish[0];
    return 0;
}