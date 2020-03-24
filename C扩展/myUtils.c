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
/// 插入节点
/// </summary>
/// <param name="linked">链表头指针</param>
/// <param name="key">新节点键</param>
/// <param name="msg">新节点消息</param>
/// <returns>int</returns>
int addNode(list *linked, int key, char *msg)
{
	if (linked == NULL)
		return 0;
	node *pitem = createNode(key, msg);
	//二级指针指向当前遍历的节点，一级指针指向当前节点的后继节点
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
/// 打印链表
/// </summary>
/// <param name="linked">链表头指针</param>
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
