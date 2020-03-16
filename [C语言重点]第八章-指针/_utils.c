#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include "_utils.h"

#pragma region 函数列表
/***************************************************
 * @comments:创建节点
 * @param key:节点编号
 * @param msg:节点信息
 * @Return node 节点指针
***************************************************/
node *createNode(int key, char *msg)
{
	node *pNode = (node*)malloc(sizeof(node));	//申请动态内存
	memset(pNode, 0, sizeof(node));	//清理脏数据
	pNode->index = key;
	pNode->message = msg;
	pNode->next = NULL;
	return pNode;
}

/***************************************************
 * @comments:向指定链表追加新节点
 * @param pHead:指定链表头指针
 * @param pNode:需追加的节点指针变量
 * @Return void
***************************************************/
void appendNode(node *pHead, node *pNode)
{
	node *tmp = pHead;	//当前节点指针
	while (tmp->next != NULL)
		tmp = tmp->next;	//将当前节点指针指向末端节点
	tmp->next = pNode;	//末端节点指针域指向追加节点首地址（添加新节点）
}

//插入元素
void insertNode(node *pHead, int key, node *pNode)
{
	node *tmp = pHead;	//当前节点
	while (tmp->next != NULL && tmp->next->index != key)	//当前节点指针指向前驱节点
	{
		tmp = tmp->next;
	}
	pNode->next = tmp->next->next;	//修改 pNode（插入节点）的后继节点为前驱节点下下个节点首地址
	tmp->next = pNode;	//修改前驱节点后继节点为 pNode (插入节点首地址)
}

//查找节点
node *findNode(node *pHead, int key)
{
	node *tmp = pHead;	//当前节点指针
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
	node *tmp = pHead,	//当前节点指针
		*del; //删除节点
	while (tmp->next != NULL && tmp->next->index != key)	//当前节点指针指向前驱节点
	{
		tmp = tmp->next;
	}
	del = tmp->next;	//获取删除节点
	tmp->next = del->next;	//前驱节点指针域指向删除节点指针域（下一节点首地址）
	free(del);	//手动回收，防止内存泄漏
	return 1;
}

//更新节点数据域
void updateNode(node *pHead, int index, char *msg)
{
	node *tmp = findNode(pHead, index);
	tmp->message = msg;
}
#pragma endregion