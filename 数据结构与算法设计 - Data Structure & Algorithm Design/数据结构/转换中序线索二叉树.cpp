#include <iostream>
using namespace std;

const int N = 100;
const int INIT_V = 10;
const int EXP = 4;
typedef char ElemType;

typedef struct Binary_Tree_Node {
	Binary_Tree_Node *lchild, *rchild;
	bool ltag, rtag;
	ElemType data;
} BTNode, *BTLink;

bool Init_BTree(BTLink &a) {
	a = (BTLink) malloc (sizeof(BTNode));
	a->ltag = a->rtag = 0;
	if (!a)
		exit(-1);
	return true;
}

void PreOrder_Con(BTLink a)
{
	char temp;
	cin >> temp;

	if (temp == ' ')
	{
		a = NULL;
		return;
	}
	else
	{
		a = (BTLink) malloc (sizeof(BTNode));
		a -> data = temp;
		PreOrder_Con(a->lchild);
		PreOrder_Con(a->rchild);
	}
}

BTLink pre=NULL;

void MidOrder_Tag(BTLink a)
{
	if (a == NULL)
		return;

	MidOrder_Tag(a->lchild);

	if (a->lchild == NULL)
	{
		a -> ltag = true;
		a -> lchild = pre;
	}

	if (pre != NULL && pre->rchild == NULL)
	{
		pre -> rtag = true;
		pre -> rchild = a;
	}

	pre = a;

	MidOrder_Tag(a->rchild);
}

void MidOrder_Tra(BTLink a, BTLink cur)
{
	if (a == NULL)
	{
		cout << " ";
		return;
	}

	MidOrder_Tra(a->lchild, a);

	if (a->ltag)
		cout << " " << a->data;
	
	if (a->rtag)
		cout << " ";
	else
	{
		MidOrder_Tra(a->rchild, a);
		if (cur == a)
			cout << a->data;
	}
}

int main(void)
{
	getchar();
	BTLink a;
	if (Init_BTree(a))
	{
		PreOrder_Con(a);
		MidOrder_Tag(a);
	}
	else
	{
		cout << "Initial failed." << endl;
		return 0;
	}


	return 0;
}

/*
if (a->ltag)
	{
		cout << a->lchill->data;
		return;
	}
	else
		MidOrder_Tra(a->lchild);
*/