#include <stdlib.h>
#include "utils.h"

#pragma region 函数列表

list *createLinks()
{
	list *linked = malloc(sizeof(list));
	linked->size = 0;
	linked->first = NULL;
	for (int i = 1; i <= 10; i++)
	{
		addNode(linked, i, i == 1 ? "首元节点" : "普通节点");
	}
	return linked;
}

//创建节点
node *createNode(int key, char *msg)
{
	node *entry = (node*)malloc(sizeof(node));
	entry->key = key;
	entry->message = msg;
	entry->next = NULL;
	return entry;
}

//添加节点
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

//插入节点
node *insertNode(list *linked, int index, node *entry)
{
	if (entry->key == 1)	//1.插入到头部
	{
		linked->first->message = "普通节点";
		entry->next = linked->first;
		linked->first = entry;
	}
	else if (index > 1 && index < linked->size)	//2.插入到中间
	{
		node *perv = findNode(linked, entry->key - 1);	//获取前驱节点
		entry->next = perv->next;
		perv->next = entry;
	}
	else //3.插入到末端
	{
		node *last = findNode(linked, linked->size);
		last->next = entry;
	}
	return linked;
}

//查找节点
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

//打印链表
void displayNodes(list *linked)
{
	node *tmp = linked->first;
	while (tmp != NULL)
	{
		printf_s("key:%d,message:%s\n", tmp->key, tmp->message);
		tmp = tmp->next;
	}
}

//维护主键（key）
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

//删除节点
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

//更新节点
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