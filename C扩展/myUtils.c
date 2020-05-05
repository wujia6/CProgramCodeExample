#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

#pragma region 函数列表
/// <summary>
/// 创建节点
/// </summary>
/// <param name="key">节点索引</param>
/// <param name="msg">节点消息</param>
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
/// 添加节点（多级指针）
/// </summary>
/// <param name="linked">链表头指针</param>
/// <param name="key">新节点键</param>
/// <param name="msg">新节点消息</param>
/// <returns>int</returns>
int ptr_addNode(list *lst, int key, char *msg)
{
	if (lst == NULL)
		return 0;
	node *entry = createNode(key, msg);
	//二级指针指向当前遍历的节点，一级指针指向当前节点的后继节点
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
/// 添加节点
/// </summary>
/// <param name="linked">链表头指针</param>
/// <param name="key">新节点键</param>
/// <param name="msg">新节点消息</param>
/// <returns>int</returns>
int addNode(list *lst, int key, char *msg)
{
	if (lst == NULL)
		return 0;
	node *newNode = createNode(key, msg);
	if (!lst->first)		//判断首元节点
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
	
	if (index == 1)	//1.插入到头部
	{
		lst->first->message = "普通节点";
		entry->next = lst->first;
		lst->first = entry;
	}
	else if (index > 1 && index < lst->len)	//2.插入到中间
	{
		node *perv = findBy(lst, index - 1);	//获取前驱节点
		entry->next = perv->next;
		perv->next = entry;
	}
	else //3.插入到末端
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
/// 打印链表
/// </summary>
/// <param name="lst">链表头指针</param>
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
