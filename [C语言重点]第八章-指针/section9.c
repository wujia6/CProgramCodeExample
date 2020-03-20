#include <stdio.h>
#include <malloc.h>
#include <string.h>

//定义节点
typedef struct node
{
	int key;    //数据域（存放构建该结构需要的数据）索引键（主键）
	char *name;
	float data;
	struct node *next; //指针域（必须是同类型，存放下一节点首地址）
} node;

//创建节点
//@param index节点索引键
//@param name节点名称
//@param data节点数据
//@Return *ptr node
node *createNodes(int index, char *name, float data)
{
	node *pNode = (node*)malloc(sizeof(node));	//申请动态内存
	memset(pNode, 0, sizeof(node));	//清空脏数据
	pNode->key = index;
	pNode->name = name;
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}

int main()
{
	#pragma region 申请动态内存
	//1.malloc函数
	//int *ptr = (int *)malloc(sizeof(int));
	//*ptr = 10;
	//printf_s("%d\n", *ptr);
	////2.释放内存空间
	//printf_s("%s\n", "正在释放ptr内存");
	//free(ptr);
	//printf_s("%d\n", *ptr);
	#pragma endregion

	#pragma region 链表节点
	//1.头节点
	//2.头指针
	//3.首元节点
	//4.前驱节点		
	//5.后继节点
	#pragma endregion

	#pragma region 创建链表
	//创建头指针并指向首元节点
	node *pHead = createNodes(1, "首元节点", 100.2);
	node *tmp = pHead;		//当前节点指针
	for (int i = 2; i <= 10; i++)
	{
		node *pNode = createNodes(i, "普通节点", 100.2 + i);
		tmp->next = pNode;
		tmp = tmp->next;
	}

	tmp = pHead;

	//访问链表
	while (tmp != NULL)
	{
		printf_s("key:%d,name:%s,data:%f\n", tmp->key, tmp->name, tmp->data);
		tmp = tmp->next;
	}
	#pragma endregion

	system("pause");
	return 0;
}