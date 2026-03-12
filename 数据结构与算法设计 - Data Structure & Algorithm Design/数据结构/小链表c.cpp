#include<iostream>
using namespace std;

typedef struct LinkNode
{
    double data;
    struct LinkNode *next;
}LinkNode, *LinkList;

bool Insert_LL(LinkList &a, int i, double e)
{
    LinkList p = a;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return false;
    LinkList new_node = (LinkList) malloc (sizeof(LinkNode));
    new_node->data = e;
    new_node->next = p->next;
    p->next = new_node;
    return true;
}

bool Delete_LL(LinkList &a, int i)
{
    LinkList p = a;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i - 1)
        return false;
    LinkList q = p->next;
    p->next = q->next;
    free(q);
    return true;
}

int main(void)
{
    int n=10;
    LinkList list;
    for (int i=1; i<=n; i++)
    {
        double temp;
        cin >> temp;
        Insert_LL(list, i, temp);
    }

    LinkList list_first = list->next;
    for (int i=0; i<n; i++)
    {
        cout << list_first->data << endl;
        list_first = list_first->next;
    }
    return 0;
}