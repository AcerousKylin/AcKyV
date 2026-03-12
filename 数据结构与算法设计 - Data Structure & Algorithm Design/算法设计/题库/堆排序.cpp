/*类型：减治法，简单循环
 *堆是一种具有特殊性质的完全二叉树，每个结点值都小于等于其左右子结点称小根堆，反之称大根堆
 *每个根以结点的层序编号作为下标，随后便可以用数组进行模拟
 *根据两种堆的性质，对无序完全二叉树进行排序，按从左往右，从上往下的顺序进行父子结点的交换
 *注意堆的父结点与子结点序号和层序编号的关系
*/
#include <iostream>
using namespace std;

int r[n] = {3, 18, 5, 8, 6, 10, 2, 15, 20};

void SiftHeap(int k, int n);
void HeapSort(int n);

int main()
{
int i, n = 9;
    HeapSort(r, n);
    for (i = 0; i < n; i++)
        cout<<r[i] <<" ";
    return 0;
}

void SiftHeap(int k, int n)
{
    int i, j, temp;
    i = k; j = 2 * i + 1; 
    while (j < n) //筛选还没有进行到叶子
    {
        if (j < n-1 && r[j] < r[j+1])
            j++; //比较i的左右孩子，j为较大者
        if (r[i] > r[j]) //根结点已经大于左右孩子中的较大者
            break; 
        else
        {
        temp = r[i]; r[i] = r[j]; r[j] = temp;; //将被筛结点与结点j交换
        i = j; j = 2 * i + 1; //被筛结点位于原来结点j的位置
        }
    }
}

void HeapSort(int n) 
{
    int i, temp;
    for (i = (n-1)/2; i >= 0; i--) //初始建堆，最后一个分支的下标是(n-1)/2
        SiftHeap(i, n) ; 
    for (i = 1; i <= n-1; i++) //重复执行移走堆顶及重建堆的操作
    {
        temp = r[0]; r[0] = r[n-i]; r[n-i] = temp;
        SiftHeap(0, n-i); //只需调整根结点
    }
}