#include <string.h>
#include <stdlib.h>
#include "utils.h"

#pragma region �����б�

list *createLinks()
{
	list *pHeader = malloc(sizeof(list));
	memset(pHeader, 0, sizeof(list));
	pHeader->size = 0;
	pHeader->header = NULL;
	return pHeader;
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
	if (pNode->key == 1)	//1.���뵽ͷ��
	{
		pHead->message = "��ͨ�ڵ�";
		pNode->next = pHead;
		pHead = pNode;
		checkPrimaries(pHead);
	}
	else if (pNode->key > 1 && pNode->key < len)	//2.���뵽�м�
	{
		node *perv = findNode(pHead, pNode->key - 1);	//��ȡǰ���ڵ�
		pNode->next = perv->next;
		perv->next = pNode;
		checkPrimaries(pHead);
	}
	else //3.���뵽ĩ��
	{
		node *last = findNode(pHead, len);
		last->next = pNode;
	}
	return pHead;
}

//��ȡ������
int getLength(node *pHead)
{
	int count = 0;
	node *tmp = pHead;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return count;
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

//��ӡ����
void displayNodes(node *pHead)
{
	node *tmp = pHead;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//ά��������key��
void checkPrimaries(node *pHead)
{
	int index = 1;
	node *tmp = pHead;
	while (tmp != NULL)
	{
		tmp->key = index;
		tmp = tmp->next;
		index++;
	}
}

//ɾ���ڵ�
int removeNode(node *pHead, int index)
{
	node *del, *perv = findNode(pHead, index - 1);
	if (perv == NULL)
		return 0;
	del = perv->next;
	perv->next = del->next;
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

#pragma endregion