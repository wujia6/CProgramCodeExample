#include <malloc.h>

#pragma region 节点
//普通节点
typedef struct listNode
{
	int key;
	char *message;
	struct listNode *next;
} node;

//头节点（链表）
typedef struct list
{
	int len;
	node *first;
} list;
#pragma endregion

#pragma region 函数原型
node *createNode(int, char *);

int ptr_addNode(list *, int, char *);

int addNode(list *, int, char *);

node *findBy(list *, int);

int insertNode(list *, int, node *);

void ptr_display(list *);
#pragma endregion


