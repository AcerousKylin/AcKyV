#include <iostream>
using namspace std;

typedef enum PointerTag{LINK, THREAD};
typedef int TElemType;
typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag, RTag;
}BiThrNode, *BiThrTree;

int InOrderTraverse_Thr(BiThrTree T, int (*visit)(TElemType e))
{
    
}