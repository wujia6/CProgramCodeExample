#include <string.h>
#include <stdlib.h>
#include "utils.h"

#pragma region 函数列表
//创建链表头
list *createLinks()
{
	list *pHead = malloc(sizeof(list)),
		*pLst = pHead;
	pLst->size = 0;
	pLst->link = NULL;
	return pLst;
}

//创建节点
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));
	memset(pNode, 0, sizeof(node));	//清空脏数据
	pNode->key = key;
	pNode->message = msg;
	pNode->next = NULL;
	return pNode;
}

//获取链表长度
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

//追加节点
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = pNode;
}

//插入节点
node *insertNode(node *pHead, node *pNode)
{
	int len = getLength(pHead);
	if (pNode->key == 1) //插入首元节点位置
	{
		pNode->next = pHead;
		pHead = pNode;
		checkPrimaries(pHead);
	}
	else if (pNode->key > 1 && pNode->key < len) //插入中间节点位置
	{
		node *before = findNode(pHead, pNode->key - 1);
		pNode->next = before->next;
		before->next = pNode;
		checkPrimaries(pHead);
	}
	else //插入末端节点
	{
		node *last = findNode(pHead, len);
		last->next = pNode;
	}
	return pHead;
}

//查找节点
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

//删除节点
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

//更新节点
int updateNode(node *pHead, int index, char *msg)
{
	node *tmp = findNode(pHead, index);
	if (tmp == NULL)
		return 0;
	tmp->message = msg;
	return 1;
}

//打印节点
void displayNodes(node *pHead)
{
	node *tmp = pHead;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//检查key键
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
