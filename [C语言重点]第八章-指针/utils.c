#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"

#pragma region �����б�
//�����ڵ�
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));
	memset(pNode, 0, sizeof(node));	//����������
	if (key > 0)
	{
		pNode->index = key;
		pNode->message = msg;
		pNode->next = NULL;
	}
	else
		pNode->next = NULL;
	return pNode;
}

//׷�ӽڵ�
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;	//��ǰ�ڵ�ָ��
	while (tmp->next != NULL)
		tmp = tmp->next;	//����ǰ�ڵ�ָ��ָ��β���ڵ�
	tmp->next = pNode;	//ĩ�˽ڵ�ָ����ָ��׷�ӽڵ��׵�ַ������½ڵ㣩
}

//����ڵ�
void insertNode(node *pHead, int key, node *pNode)
{
	node *tmp = pHead,	//��ǰ�ڵ�
		*p_before;	//ǰ���ڵ�
	while (tmp->next != NULL)
	{
		if (tmp->next->index == key)
		{
			p_before = tmp;
			break;
		}
		tmp = tmp->next;
	}
	pNode->next = p_before->next->next;	//������ڵ�ָ����ָ��ǰ���ڵ����¸��ڵ��׵�ַ
	p_before->next = pNode;	//ǰ���ڵ�ָ����ָ�����ڵ��׵�ַ
}

//���ҽڵ�
node *findNode(node *pHead, int key)
{
	node *tmp = pHead->next;	//��Ԫ�ڵ�
	while (tmp != NULL)
	{
		if (tmp->index == key)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//ɾ���ڵ�
int removeNode(node *pHead, int key)
{
	node *tmp = pHead->next;	//��Ԫ�ڵ�
	while (tmp->next != NULL && tmp->next->index != key)	//�ƶ���ǰ���ڵ�
		tmp = tmp->next;	
	node *del = tmp->next;	//��ȡɾ���ڵ�
	tmp->next = del->next;	//ǰ���ڵ�ָ����ָ��ɾ���ڵ�ָ������һ�ڵ��׵�ַ��
	free(del);	//�ֶ����գ���ֹ�ڴ�й©
	return 1;
}

//���½ڵ�������
void updateNode(node *pHead, int index, char *msg)
{
	node *p_current = findNode(pHead, index);
	p_current->message = msg;
}
#pragma endregion