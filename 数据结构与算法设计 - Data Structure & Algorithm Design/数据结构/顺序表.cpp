#include <iostream>
using namespace std;

// 类型定义

#define LISTSIZE 100;   // 最大表长
typedef int ListData;


typedef struct
{
    ListData* data;     // 存储空间基址
    int length;     //当前元素个数
} SeqList;

void InitList(SeqList &L)   // 初始化
{
    L.data = (ListData*) malloc (LISTSIZE * sizeof(ListData));
    if (L.data == NULL)
    {
        printf("Allocation of memory failed!\n");
        exit(1);
    }
    L.length = 0;
}

int Where(SeqList &L, ListData x)   // 按值查找，返回位置
{
    int i=0;
    while (i<L.length && L.data[i]!=x)
        i++;
    if (i<L.length)
        return i;
    else
        return -1;
}

int IsIn(SeqList &L, ListData x)    // 按值查找，判断
{
    int i=0, found=0;
    while (i<L.length && !found)
    {
        if (L.data[i] != x)
            i++;
        else
            found = 1;
    }
    return found;
}

int Length(SeqList &L)  // 求表长
{
    return L.length;
}

ListData GetData(SeqList &L, int i)    // 提取指定元素
{
    if (i>=0 && i<L.length)
        return L.data[i];
    else
        printf("Invalid value i!\n");
}

int Next(SeqList &L, ListData x)    // 按值寻找后继
{
    int i = Where(L, x);
    if (i>=0 && i<L.length)
        return i+1;
    else
        return -1;
}

int Pre(SeqList &L, ListData x)     //按值寻找前驱
{
    int i = Where(L, x);
    if (i>0 && i<L.length)
        return i-1;
    else
        return -1;
}

int Insert(SeqList &L, ListData x, int i)   // 插入
{
    if (i < 0 || i > L.length || L.length == LISTSIZE)
        return 0;
    else
    {
        for (int j=L.length; j<i; j--)
            L.data[j] = L.data[j-1];
        L.data[i] = x;
        L.length++;
        return 1;
    }
}

int Delete(SeqList &L, ListData x)
{
    int i = Where(L, x);
    if (i >= 0 && i < L.length)
    {
        for (int j=i; j<L.length; j++)
            L.data[j] = L.data[j+1];
        L.length--;
        return 1;
    }
    return 0;
}

void Union ( SeqList &A, SeqList &B)    // 将B并入A中
{
    int n  = Length(A);
    int m = Length(B);
    for (int i=0; i<m; i++)
    {
	    int x = GetData(B, i);   //在B中取一元素
	    int k = Where(A, x);    //在A中查找该元素
	        if (k == -1)  //若未找到则插入该元素
            {
                Insert(A, x, n);
                n++;
            }
    }
 }

void Intersection(SeqList &A, SeqList &B)   // 将AB存入A
{
    int n = Length(A);
    int m = Length(B);
    int i=0;
    while(i < n)
    {
        int x = GetData(A, i);  // 在A中取一元素
        int k = Where(B, x);    // 在B中查找该元素
        if (k == -1)
        {
            Delete(A, x);
            n--;
        }   // 在B中未找到该元素就在A中删除它
        else
            i++;
    }
}