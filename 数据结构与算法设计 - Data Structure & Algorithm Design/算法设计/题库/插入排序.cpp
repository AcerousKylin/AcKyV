/*类型：减治法，简单循环
 *依次将待排序的元素中的每一个元素插入有序区域，直到全部记录完成排序
 *利用第0个元素作为“哨兵”，暂存插入的元素以在无序区进行后移，并防止越界
*/

#include <iostream>
using namespace std;

void InsertSort(int r[], int n);

int main()
{
    int i, n = 10, r[n] = {0, 3, 18, 5, 8, 6, 10, 2, 15, 20};
    InsertSort(r, n);
    for (i = 1; i < n; i++)
        cout<<r[i]<<" ";
    return 0;
}

void InsertSort(int r[], int n)
{ 
    int i, j;
    for (i = 2; i < n; i++) //从第2个记录开始执行插入操作
    {
        r[0] = r[i]; //暂存待插记录，设置哨兵
        for (j = i - 1; r[0] < r[j]; j--) //寻找插入位置
            r[j+1] = r[j]; //记录后移
        r[j+1] = r[0];
    }
}
