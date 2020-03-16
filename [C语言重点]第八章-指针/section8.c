#include <stdio.h>
#include "utils.h"

int main()
{
	node *pHead;	//链表头指针

	#pragma region 创建链表
	pHead = createNode(1, "首元节点");
	//printf_s("key:%d，message:%s\n", pHead->key, pHead->message);
	#pragma endregion

	#pragma region 追加节点
	for (int i = 2; i <= 10; i++)
	{
		node *pLink = createNode(i, "普通节点");
		appendNode(pHead, pLink);
	}
	//displayNodes(pHead);
	#pragma endregion
	#pragma region 插入节点
	node *pNode = createNode(11, "插入的末端节点");
	pHead = insertNode(pHead, pNode);
	displayNodes(pHead);
	#pragma endregion
	puts("");
	#pragma region 删除节点
	if (removeNode(pHead, 11))
		puts("删除成功");
	else
		puts("删除失败");
	displayNodes(pHead);
	#pragma endregion
	puts("");
	#pragma region 更新节点
	printf_s("%s\n", updateNode(pHead, 5, "更新的普通节点") ? "更新成功" : "更新失败");
	displayNodes(pHead);
	#pragma endregion

	system("pause");
	return 0;
}