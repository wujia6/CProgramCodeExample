#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
	#pragma region 单链表
	depart *dep = initDepart(10, "行政部");
	employee *tmp = dep->first;
	for (int i = 0; i < 15; i++)
	{
		employee *entry = createEntrys(100 + i, "员工", 0, 20 + i);
		if (tmp)
		{
			//entry->prev = tmp;
			tmp->next = entry;
			tmp = tmp->next;
		}
		else
			tmp = dep->first = entry;
		dep->peoples++;
	}
	displayAlls(dep);
	#pragma endregion

	#pragma region 双链表
	//创建链表，添加节点
	classes *cls = initClass();
	for (int i = 0; i < 5; i++)
	{
		student *info = initStudent(i + 1, "学生", 1, 20 + i);
		addTo(cls, info);
	}
	showlist(cls);
	#pragma endregion

	system("pause");
	return 0;
}