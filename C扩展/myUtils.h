#include <malloc.h>

#pragma region 定义节点类型
//普通节点
typedef struct list_node
{
	int key;
	char *message;
	struct list_node *next;
} node;

//头节点（链表）
typedef struct list
{
	int len;
	struct list_node *header;
} list;
#pragma endregion

#pragma region 函数原型

node *createNode(int, char *);

int addNode(list *, int, char *);

void display(list *);
#pragma endregion


