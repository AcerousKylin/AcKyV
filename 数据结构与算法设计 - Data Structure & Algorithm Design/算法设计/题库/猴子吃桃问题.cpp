/*类型：递推法之逆推
 *一只猴子摘了很多桃子，每天吃现有桃子的一半多一个，
 *到第n天时只有一个桃子，问原有桃子多少个？
*/

#include <iostream>
using namespace std;
int MonkeyPeach(int n)
{//填写代码，完成函数定义：
    if (n == 1)
        return 1;
    else
        return 2 * (MonkeyPeach(n-1) + 1);
}
int main()
{   int n;
    cin>>n;
    cout << MonkeyPeach(n);
    return 0;
}
