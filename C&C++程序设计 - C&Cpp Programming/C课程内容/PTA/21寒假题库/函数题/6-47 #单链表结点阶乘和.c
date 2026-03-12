#include <stdio.h>
#include <stdlib.h>

typedef struct Node *PtrToNode; // Node的指针类型定义为PtrToNode
struct Node {
    int Data; /* 存储结点数据 */
    PtrToNode Next; /* 指向下一个结点的指针 */
};
typedef PtrToNode List; /* 定义单链表类型 List=PtrToNode? */

int FactorialSum( List L );

int main()
{
    int N, i;
    List L, p;

    scanf("%d", &N);
    L = NULL;
    for ( i=0; i<N; i++ ) {
        p = (List)malloc(sizeof(struct Node)); // 申请大小为结构体Node的动态空间
        scanf("%d", &p->Data); // 键入结点数据
        p->Next = L; // L作为下一个结点的指针被输入p
        L = p; // 将p作为下一个结点将要输入的指针
    }   // 最先输入的数据被存在最内部的结点中
    printf("%d\n", FactorialSum(L));

    return 0;
}

/* 你的代码将被嵌在这里 */

int Factory( int n )
{
    if (n==1 || n==0)
        return 1;
    else
        return n * Factory(n-1);
}

int FactorialSum( List L )
{
    int sum=0;
    while(L!=NULL)
    {
        sum += Factory(L->Data);
        L = L->Next;
    }
    return sum;
}