#include <malloc.h>

#pragma region ����ڵ�����
//��ͨ�ڵ�
typedef struct list_node
{
	int key;
	char *message;
	struct list_node *next;
} node;

//ͷ�ڵ㣨����
typedef struct list
{
	int len;
	struct list_node *header;
} list;
#pragma endregion

#pragma region ����ԭ��

node *createNode(int, char *);

int addNode(list *, int, char *);

void display(list *);
#pragma endregion


