#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "utils.h"

#pragma region 函数列表
//创建节点
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));
	memset(pNode, 0, sizeof(node));	//清理脏数据
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

//追加节点
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;	//当前节点指针
	while (tmp->next != NULL)
		tmp = tmp->next;	//将当前节点指针指向尾部节点
	tmp->next = pNode;	//末端节点指针域指向追加节点首地址（添加新节点）
}

//插入节点
void insertNode(node *pHead, int key, node *pNode)
{
	node *tmp = pHead,	//当前节点
		*p_before;	//前驱节点
	while (tmp->next != NULL)
	{
		if (tmp->next->index == key)
		{
			p_before = tmp;
			break;
		}
		tmp = tmp->next;
	}
	pNode->next = p_before->next->next;	//待插入节点指针域指向前驱节点下下个节点首地址
	p_before->next = pNode;	//前驱节点指针域指向插入节点首地址
}

//查找节点
node *findNode(node *pHead, int key)
{
	node *tmp = pHead->next;	//首元节点
	while (tmp != NULL)
	{
		if (tmp->index == key)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

//删除节点
int removeNode(node *pHead, int key)
{
	node *tmp = pHead->next;	//首元节点
	while (tmp->next != NULL && tmp->next->index != key)	//移动到前驱节点
		tmp = tmp->next;	
	node *del = tmp->next;	//获取删除节点
	tmp->next = del->next;	//前驱节点指针域指向删除节点指针域（下一节点首地址）
	free(del);	//手动回收，防止内存泄漏
	return 1;
}

//更新节点数据域
void updateNode(node *pHead, int index, char *msg)
{
	node *p_current = findNode(pHead, index);
	p_current->message = msg;
}
#pragma endregion