#include <iostream>
using namespace std;

typedef char TreeData;
typedef struct node
{
    TreeData data;
    struct node *leftChild, *rightChild;
}BinTreeNode, *BinTree;

void Destory(BinTreeNode *current)  // 删除根为current的子树
{
    if (current != NULL)
    {
        Destory(current -> leftChild);
        Destory(current -> rightChild);
        delete current;
    }
}

BinTreeNode *Parent(BinTreeNode *start, BinTreeNode *current)   // 找到当前结点的父结点
{
    if (start == NULL)
        return NULL;
    if (start->leftChild == current || start->rightChild == current)
        return start;
    BinTreeNode *p;
    if ((p = Parent(start->leftChild, current)) != NULL)    // 查找左子树
        return p;
    else
        return Parent(start->rightChild, current);  // 查找右子树
}

void InOrder_R(BinTreeNode *T)    // 中序遍历二叉树递归算法
{
    if (T != NULL)
    {
        InOrder_R(T->leftChild);
        cout << T->data;
        InOrder_R(T->rightChild);
    }
}

void PreOrder_R(BinTreeNode *T)   // 前序遍历二叉树递归算法
{
    if (T != NULL)
    {
        cout << T->data;
        PreOrder_R(T->leftChild);
        PreOrder_R(T->rightChild);
    }
}

void PostOrder_R(BinTreeNode *T)  // 后序遍历二叉树递归算法
{
    if (T != NULL)
    {
        PostOrder_R(T->leftChild);
        PostOrder_R(T->rightChild);
        cout << T->data;
    }
}

const TreeData RefValue = -1;
void Create(ifstream &in, BinTreeNode *&T)  // 创建前序建立二叉树递归算法
{
    TreeData x;
    if(!in.eof())
    {
        in >> x;    // 读入根结点的值
        if (x !=RefValue)   // RefValue即在输入序列中表示空结点的符号
        {
            T = new BinTreeNode;    // 建立根结点
            if (T == NULL)
            {
                cerr << "Allocation of memory failed!" << endl;
                exit(1);
            }
            T->data = x;
            Create(in, T->leftChild);
            Create(in, T->rightChild);
        }
        else
            T = NULL;
    }
}

int Count(BinTreeNode *T)   // 计算二叉树结点个数递归算法
{
    if (T == NULL)
        return 0;
    else
        return 1 + Count(T->leftChild) + Count(T->rightChild);
}

int Leaf_Count(BinTree T)   // 计算二叉树叶子结点个数递归算法
{
    if (!T)
        return 0;
    else if (!T->leftChild && !T->rightChild)
        return 1;
    else
        return Leaf_Count(T->leftChild) + Leaf_Count(T->rightChild);
}

int Height(BinTreeNode *T)  // 计算二叉树高度递归算法
{
    if (T == NULL)
        return 0;
    else
    {
        int m = Height(T->leftChild);
        int n = Height(T->rightChild);
        return (m>n)>m+1:n+1;
    }
}

int Copy(BinTreeNode *T)    // 复制二叉树
{
    if (T == NULL)
        return -1;
    BinTreeNode *temp = new BinTreeNode;
    temp->data = T->data;
    temp->leftChild = Copy(T->leftChild);
    temp->rightChild = Copy(T->rightChild);
    return temp;
}

int IsEqual(BinTreeNode *a, BinTreeNode *b) // 判断两个二叉树是否完全相等
{
    int wan = (a == NULL), wbn(b == NULL)
    if (a == NULL && b == NULL)
        return 1;
    int wde = (a->data == b->data);
    int wae = (Equal(a->leftChild, b->leftChild) && Equal(a->rightChild, b->rightChild));
    if (wan && wbn && wde && wae)
        return 1;
    else
        return 0;
}

void InOrder_S(BinTree T)   // 中序遍历二叉树堆栈算法
{
    stack S;
    InitStack(&S);  // 递归工作栈
    BinTreeNode *p = T;
    while (p!=NULL || !StackEmpty(&S))
    {
        while (p != NULL)
        {
            Push(&S, p);
            p = p->leftChild;
        }
        if (!StackEmpty(&S))
        {
            Pop(&S, p); // 退栈
            cout << p->data << endl;    // 访问根
            p = p->rightChild;
        }
    }
    return;
}

void PreOrder_S(BinTree T)  // 前序遍历二叉树堆栈算法
{
    stack S;
    InitStack(&S);  // 递归工作栈
    BinTreeNode *p = T;
    push(&S, NULL);
    while(p != NULL)
    {
        cout << p->data << endl;
        if (p->rightChild != NULL)
            push(&S, p->rightChild);
        if (p->leftChild != NULL)
            p = p->leftChild;   // 进左子树
        else
            Pop(&S, p);
    }
}

void SwapLnR_R(BinTreeNode *T)
{
    BinTreeNode *p = T, *temp;
    if (p != NULL)
    {
        temp = p->leftChild;
        p->leftChild = p->rightChild;
        p->rightChild = temp;
        SwapLnR(p->leftChild);
        SwapLnR(p->rightChild);
        /*最后一个递归可替换为：
        p = p->rightChild;
        */
    }
}

void SwapLnR_S(BinTreeNode *T)
{
    BinTreeNode *p, *temp;
    stack S;
    InitEmpty(&S);
    if (T != NULL)
    {
        push(&S, T);
        while(!StackEmpty(&S))
        {
            Pop(&S, p);
            temp = p->leftChild;
            p->leftChild = p->rightChild;
            p->rightChild = temp;
            if (p->rightChild != NULL)
                push(&S, p->rightChild);
            if (p->leftChild != NULL)
                push(&S, p->leftChild);
        }
    }
}