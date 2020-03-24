#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

#pragma region �����б�
/// <summary>
/// �����ڵ�
/// </summary>
/// <param name="key">�ڵ�����</param>
/// <param name="msg">�ڵ���Ϣ</param>
/// <returns>node *p</returns>
node *createNode(int key, char *msg)
{
	node *pNode = malloc(sizeof(node));
	pNode->key = key;
	pNode->message = msg;
	pNode->next = NULL;
	return pNode;
}

/// <summary>
/// ����ڵ�
/// </summary>
/// <param name="linked">����ͷָ��</param>
/// <param name="key">�½ڵ��</param>
/// <param name="msg">�½ڵ���Ϣ</param>
/// <returns>int</returns>
int addNode(list *linked, int key, char *msg)
{
	if (linked == NULL)
		return 0;
	node *pitem = createNode(key, msg);
	//����ָ��ָ��ǰ�����Ľڵ㣬һ��ָ��ָ��ǰ�ڵ�ĺ�̽ڵ�
	node **model = &linked->header;
	while (*model && (*model)->key < key)
	{
		model = &(*model)->next;
	}
	pitem->next = *model;
	*model = pitem;
	linked->len++;
	return 1;
}

/// <summary>
/// ��ӡ����
/// </summary>
/// <param name="linked">����ͷָ��</param>
void display(list *linked)
{
	node **tmp = &linked->header;
	while (*tmp)
	{
		printf_s("key:%d,message:%s\n", (*tmp)->key, (*tmp)->message);
		tmp = &(*tmp)->next;
	}
}
#pragma endregion
