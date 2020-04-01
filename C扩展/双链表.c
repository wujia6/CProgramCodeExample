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

	puts("====================删除节点======================");
	if (deleteAt(cls, 3))
	{
		showList(cls);
	}

	puts("====================更新节点======================");
	student *inf = createStudent(2, "更新的学生", 0, 18);
	if (updateTo(cls, inf))
	{
		showList(cls);
	}

	system("pause");
	return 0;
}