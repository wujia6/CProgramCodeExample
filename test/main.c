#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int main()
{
	#pragma region ������
	depart *dep = initDepart(10, "������");
	employee *tmp = dep->first;
	for (int i = 0; i < 15; i++)
	{
		employee *entry = createEntrys(100 + i, "Ա��", 0, 20 + i);
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

	#pragma region ˫����
	//����������ӽڵ�
	classes *cls = initClass();
	for (int i = 0; i < 5; i++)
	{
		student *info = initStudent(i + 1, "ѧ��", 1, 20 + i);
		addTo(cls, info);
	}
	showlist(cls);
	#pragma endregion

	system("pause");
	return 0;
}