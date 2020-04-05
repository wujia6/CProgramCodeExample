#include <stdio.h>
#include <stdlib.h>
#include "listUtils.h"

int main()
{
	//创建链表
	classes *cls = initClasses();

	#pragma region 添加节点
	puts("====================添加节点======================");
	for (int i = 0; i < 5; i++)
	{
		student *info = createStudent(i + 1, "学生", 1, 20 + i);
		addTo(cls, info);
	}
	showList(cls);
	#pragma endregion

	#pragma region 插入节点
	puts("====================插入节点======================");
	student *info = createStudent(6, "插班生", 1, 19);
	if (insertTo(cls,5,info))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region 更新节点
	puts("====================更新节点======================");
	student *inf = createStudent(2, "更新", 1, 19);
	if (updateTo(cls, inf))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region 删除节点
	puts("====================删除节点======================");
	if (deleteAt(cls, 4))
	{
		showList(cls);
	}
	#pragma endregion

	system("pause");
	return 0;
}