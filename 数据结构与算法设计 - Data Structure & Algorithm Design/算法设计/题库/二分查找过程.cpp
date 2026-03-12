/*类型：减治法
 *在编程模板中已经声明并初始化了大小为15的整型数组，数组元素的值为其索引值的十倍，请大家不要修改该数组。
 *利用二分检索算法在该数组中查找系统给出的整型关键字k。以字符可视化的方式输出算法执行过程中以减半的速度缩小问题实例规模的过程
 *（一次减半用一行字符表示）。
*/

#include <iostream>
using namespace std;
int main()
{
    int r[15],low=0,high=14,mid,i,j,k;
    for(i=0;i<15;i++)
        r[i]=i*10;
    cin>>k;//上面的代码不能修改
    //请把你的代码写在下面循环里：
    while(low<=high)
    {
        mid = (low + high) / 2;
        if (k < r[mid])
            high = mid - 1;
        else if (k > mid)
            low = mid + 1;
        else
            low = high = mid;
        
        if (r[mid] != k)
        {
            for (i=0; i<low; i++)
                cout << "X";
            for (i=low; i<=high; i++)
                cout << "?";
            for (i=high+1; i<15; i++)
                cout << "X";
            cout << endl;
        }
        else
        {
            for (i=0; i<mid; i++)
                cout << "X";
            cout << "!";
            for (i=mid+1; i<15; i++)
                cout << "X";
            cout << endl;
            break;
        }
    }
    return 0;
}
