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
/// ��ӽڵ㣨�༶ָ�룩
/// </summary>
/// <param name="linked">����ͷָ��</param>
/// <param name="key">�½ڵ��</param>
/// <param name="msg">�½ڵ���Ϣ</param>
/// <returns>int</returns>
int ptr_addNode(list *lst, int key, char *msg)
{
	if (lst == NULL)
		return 0;
	node *entry = createNode(key, msg);
	//����ָ��ָ��ǰ�����Ľڵ㣬һ��ָ��ָ��ǰ�ڵ�ĺ�̽ڵ�
	node **model = &lst->first;
	while (*model && (*model)->key < key)
	{
		model = &(*model)->next;
	}
	entry->next = *model;
	*model = entry;
	lst->len++;
	return 1;
}

/// <summary>
/// ��ӽڵ�
/// </summary>
/// <param name="linked">����ͷָ��</param>
/// <param name="key">�½ڵ��</param>
/// <param name="msg">�½ڵ���Ϣ</param>
/// <returns>int</returns>
int addNode(list *lst, int key, char *msg)
{
	if (lst == NULL)
		return 0;
	node *newNode = createNode(key, msg);
	if (!lst->first)		//�ж���Ԫ�ڵ�
		lst->first = newNode;
	else
	{
		node *tmp = lst->first;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = newNode;
	}
	lst->len++;
	return 1;
}

int insertNode(list *lst, int index, node *entry)
{
	if (lst == NULL)
		return 0;
	
	if (index == 1)	//1.���뵽ͷ��
	{
		lst->first->message = "��ͨ�ڵ�";
		entry->next = lst->first;
		lst->first = entry;
	}
	else if (index > 1 && index < lst->len)	//2.���뵽�м�
	{
		node *perv = findBy(lst, index - 1);	//��ȡǰ���ڵ�
		entry->next = perv->next;
		perv->next = entry;
	}
	else //3.���뵽ĩ��
	{
		node *last = findBy(lst, lst->len);
		last->next = entry;
	}
	return 1;
}

node *findBy(list *lst, int index)
{
	node *tmp = lst->first;
	if (!tmp)
	{
		for (int i = 1; i <= lst->len; i++, tmp = tmp->next)
		{
			if (i == index)
				return tmp;
		}
	}
	return NULL;
}

/// <summary>
/// ��ӡ����
/// </summary>
/// <param name="lst">����ͷָ��</param>
void ptr_display(list *lst)
{
	node **tmp = &lst->first;
	while (*tmp)
	{
		printf_s("key:%d,message:%s\n", (*tmp)->key, (*tmp)->message);
		tmp = &(*tmp)->next;
	}
}
#pragma endregion
