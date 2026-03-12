/*要点.模拟法，做好问题向符号的映射，然后按照题目描述的过程，在符号上进行操作。
 *设 n(n>0)个人围成一个环，n个人的编号分别为1，2，…，n
 *从第 1 个人开始报数，报到 m 时停止报数，报 m 的人出环
 *再从他的下一个人起重新报数，报到 m 时停止报数，报m的人出环
 *如此下去，直到所有人全部出环为止。
 *对于任意给定 n 和 m，求 n 个人出环的次序。
*/

#include <iostream>
using namespace std;
int main()
{
    int r[10000]={0}, n, m;
    int counter, i = -1, num = 0;
    cin>>n>>m;
    while (num < n-1)
    {
        counter = 0;
        while (counter < m)
        {
            i = (i + 1) % n;
            if (r[i] == 0)
                counter++;
        }
        r[i] = 1;
        num++;
    }
    
    for (i = 0; i < n; i++)
        if (r[i] == 0)   //返回编号
            cout << i+1;
    return 0;
}
