#include <iostream>

using namespace std;

int main()
{   int fish[100],i, n, flag = 0;
    cin>>n;
    fish[0] = 1;    //下面的循环从鱼数n+1开始正推和枚举，请完成代码：
    // fish[i] = (fish[i-1]-1)/n*(n-1)
    while (!flag)
    {
        for (i=0; i<n; i++)
        {
            if ( (fish[i] - 1) % n != 0 || fish[i] == 0)
            {
                fish[0]++;
                break;
            }
            else
            {
                if (i == n-1)
                {
                    flag = 1;
                    break;
                }
                fish[i+1] = (fish[i] - 1) / n * (n - 1);
                // cout << "fisherman" << i+1 << " will see " << fish[i+1] << " fishes." << endl;
            }
        }
    }

    cout << fish[0];
    return 0;
}