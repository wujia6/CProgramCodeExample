#include <stdlib.h>
#include "utils.h"

#pragma region �����б�

list *createLinks()
{
	list *linked = malloc(sizeof(list));
	linked->size = 0;
	linked->first = NULL;
	for (int i = 1; i <= 10; i++)
	{
		addNode(linked, i, i == 1 ? "��Ԫ�ڵ�" : "��ͨ�ڵ�");
	}
	return linked;
}

//�����ڵ�
node *createNode(int key, char *msg)
{
	node *entry = (node*)malloc(sizeof(node));
	entry->key = key;
	entry->message = msg;
	entry->next = NULL;
	return entry;
}

//��ӽڵ�
void addNode(list *linked, int key, char *msg)
{
	node *entry = createNode(key, msg);
	node *tmp = linked->first;
	if (!linked->first)
	{
		linked->first = entry;
		return;
	}
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = entry;
	linked->size++;
}

//����ڵ�
node *insertNode(list *linked, int index, node *entry)
{
	if (entry->key == 1)	//1.���뵽ͷ��
	{
		linked->first->message = "��ͨ�ڵ�";
		entry->next = linked->first;
		linked->first = entry;
	}
	else if (index > 1 && index < linked->size)	//2.���뵽�м�
	{
		node *perv = findNode(linked, entry->key - 1);	//��ȡǰ���ڵ�
		entry->next = perv->next;
		perv->next = entry;
	}
	else //3.���뵽ĩ��
	{
		node *last = findNode(linked, linked->size);
		last->next = entry;
	}
	return linked;
}

//���ҽڵ�
node *findNode(list *linked, int index)
{
	node *tmp = linked->first;
	while (tmp != NULL)
	{
		if (tmp->key == index)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//��ӡ����
void displayNodes(list *linked)
{
	node *tmp = linked->first;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//ά��������key��
void checkPrimaries(list *linked)
{
	int index = 1;
	node *tmp = linked->first;
	while (tmp != NULL)
	{
		tmp->key = index;
		tmp = tmp->next;
		index++;
	}
}

//ɾ���ڵ�
int removeNode(list *linked, int index)
{
	node *del, *perv = findNode(linked, index - 1);
	if (perv == NULL)
		return 0;
	del = perv->next;
	perv->next = del->next;
	free(del);
	return 1;
}

//���½ڵ�
int updateNode(list *linked, int index, int key, char *msg)
{
	node *tmp = findNode(linked, index);
	if (tmp == NULL)
		return 0;
	tmp->key = key;
	tmp->message = msg;
	return 1;
}

#pragma endregion