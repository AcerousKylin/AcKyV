/*用连续整数检测算法计算GCD(m, n)，求需几次减一操作。
 *求连续整数检测算法计算GCD(m, n)算法中需要减法计算的次数。
 *（解空间为min(m,n）down to 1的连续整数，需要由大到小一次检测这个解空间直至符合约束条件
 *即同时整除m和为止。最好情况GCD(m,n)=min(m,n)，需0次减一操作，最差情况是GCD(m,n)=1，需min(m,n)-1次减一操作。）
*/

#include <iostream>
using namespace std;
int main()
{
    int t,m,n,counter=0;
    cin>>m>>n;
    for (t=(m<n)?m:n; t>=1; t--)
    {
        if (m % t == 0 && n % t == 0)
            break;
        else
            counter++;
    }
    cout << counter;
    return 0;
}