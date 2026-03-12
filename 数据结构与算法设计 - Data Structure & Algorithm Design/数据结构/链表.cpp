#include <iostream>
using namespace std;

typedef char ListData;

typedef struct node // 链表节点
{
    ListData data;      // 结点数据域
    struct node *link;  // 结点链域
} ListNode, *LinkList;

LinkList first; // 链表头指针

int Insert(LinkList &first, int x, int i)   // 在链表第i个结点处插入元素x
{
    ListNode *p = first;
    int k = 0;
    if (p == NULL)
    {
        printf("Invalid insert position!\n");
        return 0;
    }
    while (p != NULL && k < i-1)    // 找到第i-1个结点
    {
        p = p->link;
        k++;
    }
    ListNode* newnode = (ListNode*) malloc (sizeof(ListNode));  // 创建新结点
    newnode->data = x;
    if (first == NULL || i == 1)
    {
        newnode->link = first;  // 新结点成为第一个结点
        first = newnode;    // 头指针指向新结点
    }   // 插入空表或插入在非空表第一个结点之前
    else
    {
        newnode->link = p->link;
        p->link = newnode;
    }   // 插在表中或表尾
    return 1;
}

int Delete(LinkList &first, int i)  // 删除第i个结点，并返回第i个结点的值
{
    ListNode *p, *q;    // q为待删除结点，p为待删除结点的前一个结点
    if(i == 0)
    {
        q = first;
        if (q != NULL)
            first = first->link;
        else
            exit(1);
    }   // 删除表中的第1个结点
    else
    {
        p = first;
        int k = 0;
        while (p != NULL && k < i-1)
        {
            p = p->link;
            k++;
        }
        if (p == NULL || (i-1) < -1)
        {
            printf("Invalid insert position!\n");
            return 0;
        }
        else
        {
            q = p->link;
            p->link = q->link;
        }
        k = q->data;
        free(q);
        return k;
    }   // 删除其他结点
}

LinkList CreateList_F(void) // 前插法建立单链表
{
    char ch;
    ListNode *q;
    LinkList head = (LinkList) malloc (sizeof(ListNode));   // 建立表头结点
    head->link = NULL;
    while ((ch=getchar()) != '\n')
    {
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = ch;   // 建立新结点
        q->link = head->link;   // 插入表前端
        head->link = q;
    }
    return head;
}

LinkList CreateList_R(void) // 后插法建立单链表
{
    char ch;
    LinkList head = (LinkList) malloc (sizeof(ListNode));   // 建立表头结点
    head->link = NULL;
    ListNode *q, *r = NULL; // q为临时结点，r为尾指针
    r = head;
    while ((ch=getchar()) != '\n')
    {
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = ch;   // 建立新结点
        q->link = r->link;
        r->link = q;    // 插到表末端
        r = q;
    }
    r->link = NULL;
    return head;
}

void Empty(LinkList first)  // 单链表清空
{
    ListNode *q, last=NULL;
    while (first->link != NULL)  // 当链不为空时，循环逐个删除所有节点
    {
        q = first->link;
        first->link = q->link;
        free(q);
    }
    last = first;
}   // 删除链表中除表头结点外的其他所有结点

int Length(LinkList first)  // 计算单链表长度
{
    ListNode *p = first->link;  // p指向第一个结点
    int count = 0;
    while (p != NULL)
    {
        p = p->link;
        count++;
    }   // 逐个结点检测
    return count;
}

ListNode* Where(LinkList first, ListData value) // 在链表中搜索值为value的结点
{
    ListNode p = first->link;   // p指向第一个结点
    while (p != NULL && p->data != value)
        p = p->link;
    return p;
}

ListNode *Locate(LinkList first, int i) // 返回表中第i个元素的地址
{
    if (i < 0)
        return NULL;
    ListNode *p = first;
    int k = 0;
    while (p != NULL && k < i)
    {
        p = p->link;
        k++;
    }   // 找第i个结点
    if (k == i)
        return p;   // 返回第i个结点地址
    else
        return NULL;
}

/*  静态链表
int Where(SLinkList SL, ListData x) // 查找值为x的元素，返回其位序
{
    int p = SL.Nodes[0].link;   // 指针p指向链表第一个结点
    while (p != -1) // 逐个查找有给定值的结点
    {
        if (SL.Nodes[p].data != x)
            p = SL.Nodes[p].link;
        else
            break;
    }
    return p;
}

int Locate(SLinkList SL, int i)
{
    if (i < 0)
        return -1;
    int j = 0, p = SL.Nodes[0].link;
    while (p != -1 && j < i)
    {
        p = SL.Nodes[p].link;
        j++;
    }
    if (i == 0)
        return 0;
    return p;
}
*/

/*循环单链表
int Length(struct node *head)   // 求循环单链表的长度，并依次输出结点的值
{
    int length = O;
    struct node *p;
    p = head->next;
    while (p != head)
    {
        printf("%d", p->data);
        length++;
        p = p->next;
    }
    return length;
}
*/

// 双向链表
typedef struct dnode
{
    ListNode data;
    struct dnode *prior, *next;
}DblNode, *DblList; // 定义

int Length(DBlList first)
{
    DblNode *p = first->next;
    int count = 0;
    while (p != first)
    {
        p = p->next;
        count++;
    }
    return count;
}