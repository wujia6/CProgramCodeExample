#include <stdio.h>
#include "utils.h"

int main()
{
	node *pHead;	//链表头指针

	#pragma region 创建链表
	//示例：创建链表 0表示创建头节点
	pHead = createNode(0, NULL);
	#pragma endregion

	#pragma region 追加节点
	//向链表追加10个节点
	for (int i = 1; i <= 10; i++)
	{
		appendNode(pHead, createNode(i, "节点 " + i));
	}
	#pragma endregion

	#pragma region 插入节点
	node newNode = { 11,"新插入节点",NULL }, *p_insert = &newNode;
	insertNode(pHead, 9, p_insert);
	#pragma endregion

	#pragma region 查找节点
	//示例：查找数据域为5的节点
	node *p_find = findNode(pHead, 5);
	p_find == NULL ? puts("不存在该节点") : printf_s("id:%d,msg:%s\n", p_find->index, p_find->message);
	free(p_find);
	#pragma endregion

	#pragma region 删除节点
	//示例：删除节点
	if(removeNode(pHead, 9))
		puts("提示：已删除指定节点");
	#pragma endregion
	
	#pragma region 更新节点
	updateNode(pHead, 7, "刚才修改的节点");
	#pragma endregion

	#pragma region 动态内存分配
	//示例：申请动态内存
	student *ps = (student*)malloc(sizeof(student));
	ps->stuId = 1001;
	ps->stuName = "张三";
	ps->stuGender = 'M';
	ps->stuScore = 62.5;
	printf_s("学号：%d,姓名：%s,性别：%s,成绩：%f\n", ps->stuId, ps->stuName, ps->stuGender == 'M' ? "男" : "女", ps->stuScore);
	ps = (student*)calloc(2, sizeof(student));	//申请内存长度2
	free(ps);	//清空
	#pragma endregion

	system("pause");
	return 0;
}


