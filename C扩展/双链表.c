#include <stdio.h>
#include <stdlib.h>
#include "listUtils.h"

int main()
{
	#pragma region 创建双链表
	puts("====================创建双链表======================");
	//创建链表，添加节点
	classes *cls = initClasses();
	#pragma endregion

	#pragma region 添加节点
	puts("====================添加节点======================");
	for (int i = 0; i < 5; i++)
	{
		student *info = createStudent(i + 1, "学生", 1, 20 + i);
		addTo(cls, info);
	}
	showlist(cls);
	#pragma endregion

	#pragma region 插入节点
	puts("====================插入节点======================");
	student *info = createStudent(6, "插班生", 1, 19);
	if (insertTo(cls,5,info))
	{
		showlist(cls);
	}
	#pragma endregion

	system("pause");
	return 0;
}