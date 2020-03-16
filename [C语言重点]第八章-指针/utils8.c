#include <string.h>
#include <stdlib.h>
#include "utils.h"

#pragma region �����б�
//��������ͷ
list *createLinks()
{
	list *pHead = malloc(sizeof(list)),
		*pLst = pHead;
	pLst->size = 0;
	pLst->link = NULL;
	return pLst;
}

//�����ڵ�
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));
	memset(pNode, 0, sizeof(node));	//���������
	pNode->key = key;
	pNode->message = msg;
	pNode->next = NULL;
	return pNode;
}

//��ȡ������
int getLength(node *pHead)
{
	int len = 0;
	node *tmp = pHead;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return len;
}

//׷�ӽڵ�
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = pNode;
}

//����ڵ�
node *insertNode(node *pHead, node *pNode)
{
	int len = getLength(pHead);
	if (pNode->key == 1) //������Ԫ�ڵ�λ��
	{
		pNode->next = pHead;
		pHead = pNode;
		checkPrimaries(pHead);
	}
	else if (pNode->key > 1 && pNode->key < len) //�����м�ڵ�λ��
	{
		node *before = findNode(pHead, pNode->key - 1);
		pNode->next = before->next;
		before->next = pNode;
		checkPrimaries(pHead);
	}
	else //����ĩ�˽ڵ�
	{
		node *last = findNode(pHead, len);
		last->next = pNode;
	}
	return pHead;
}

//���ҽڵ�
node *findNode(node *pHead, int index)
{
	node *tmp = pHead;
	while (tmp != NULL)
	{
		if (tmp->key == index)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//ɾ���ڵ�
int removeNode(node *pHead, int index)
{
	node *del, *prev = findNode(pHead, index - 1);
	if (prev ==NULL)
		return 0;
	del = prev->next;
	prev->next == del->next;
	free(del);
	return 1;
}

//���½ڵ�
int updateNode(node *pHead, int index, char *msg)
{
	node *tmp = findNode(pHead, index);
	if (tmp == NULL)
		return 0;
	tmp->message = msg;
	return 1;
}

//��ӡ�ڵ�
void displayNodes(node *pHead)
{
	node *tmp = pHead;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//���key��
void checkPrimaries(node *pHead)
{
	node *tmp = pHead;
	int i = 1;
	while (tmp != NULL)
	{
		tmp->key = i;
		tmp = tmp->next;
		i++;
	}
}
#pragma endregion
