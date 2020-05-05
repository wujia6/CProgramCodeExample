#include <malloc.h>

#pragma region �ڵ�
//��ͨ�ڵ�
typedef struct listNode
{
	int key;
	char *message;
	struct listNode *next;
} node;

//ͷ�ڵ㣨����
typedef struct list
{
	int len;
	node *first;
} list;
#pragma endregion

#pragma region ����ԭ��
node *createNode(int, char *);

int ptr_addNode(list *, int, char *);

int addNode(list *, int, char *);

node *findBy(list *, int);

int insertNode(list *, int, node *);

void ptr_display(list *);
#pragma endregion


