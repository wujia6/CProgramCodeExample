#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "_utils.h"

#pragma region �����б�
/***************************************************
 * @comments:�����ڵ�
 * @param key:�ڵ���
 * @param msg:�ڵ���Ϣ
 * @Return node �ڵ�ָ��
***************************************************/
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));	//���붯̬�ڴ�
	memset(pNode, 0, sizeof(node));	//����������
	pNode->index = key;
	pNode->message = msg;
	pNode->next = NULL;
	return pNode;
}

/***************************************************
 * @comments:��ָ������׷���½ڵ�
 * @param pHead:ָ������ͷָ��
 * @param pNode:��׷�ӵĽڵ�ָ�����
 * @Return void
***************************************************/
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;	//��ǰ�ڵ�ָ��
	while (tmp->next != NULL)
		tmp = tmp->next;	//����ǰ�ڵ�ָ��ָ��ĩ�˽ڵ�
	tmp->next = pNode;	//ĩ�˽ڵ�ָ����ָ��׷�ӽڵ��׵�ַ������½ڵ㣩
}

//����Ԫ��
void insertNode(node *pHead, int key, node *pNode)
{
	node *tmp = pHead;	//��ǰ�ڵ�
	while (tmp->next != NULL && tmp->next->index != key)	//��ǰ�ڵ�ָ��ָ��ǰ���ڵ�
	{
		tmp = tmp->next;
	}
	pNode->next = tmp->next->next;	//�޸� pNode������ڵ㣩�ĺ�̽ڵ�Ϊǰ���ڵ����¸��ڵ��׵�ַ
	tmp->next = pNode;	//�޸�ǰ���ڵ��̽ڵ�Ϊ pNode (����ڵ��׵�ַ)
}

//���ҽڵ�
node *findNode(node *pHead, int key)
{
	node *tmp = pHead;	//��ǰ�ڵ�ָ��
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
	node *tmp = pHead,	//��ǰ�ڵ�ָ��
		*del; //ɾ���ڵ�
	while (tmp->next != NULL && tmp->next->index != key)	//��ǰ�ڵ�ָ��ָ��ǰ���ڵ�
	{
		tmp = tmp->next;
	}
	del = tmp->next;	//��ȡɾ���ڵ�
	tmp->next = del->next;	//ǰ���ڵ�ָ����ָ��ɾ���ڵ�ָ������һ�ڵ��׵�ַ��
	free(del);	//�ֶ����գ���ֹ�ڴ�й©
	return 1;
}

//���½ڵ�������
void updateNode(node *pHead, int index, char *msg)
{
	node *tmp = findNode(pHead, index);
	tmp->message = msg;
}
#pragma endregion