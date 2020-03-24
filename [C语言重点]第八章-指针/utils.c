#include <string.h>
#include <stdlib.h>
#include "utils.h"

#pragma region 函数列表

list *createLinks()
{
	list *pHeader = malloc(sizeof(list));
	memset(pHeader, 0, sizeof(list));
	pHeader->size = 0;
	pHeader->header = NULL;
	return pHeader;
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
	if (pNode->key == 1)	//1.插入到头部
	{
		pHead->message = "普通节点";
		pNode->next = pHead;
		pHead = pNode;
		checkPrimaries(pHead);
	}
	else if (pNode->key > 1 && pNode->key < len)	//2.插入到中间
	{
		node *perv = findNode(pHead, pNode->key - 1);	//获取前驱节点
		pNode->next = perv->next;
		perv->next = pNode;
		checkPrimaries(pHead);
	}
	else //3.插入到末端
	{
		node *last = findNode(pHead, len);
		last->next = pNode;
	}
	return pHead;
}

//获取链表长度
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

//打印链表
void displayNodes(node *pHead)
{
	node *tmp = pHead;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//维护主键（key）
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

//删除节点
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

//更新节点
int updateNode(node *pHead, int index, char *msg)
{
	node *tmp = findNode(pHead, index);
	if (tmp == NULL)
		return 0;
	tmp->message = msg;
	return 1;
}

#pragma endregion