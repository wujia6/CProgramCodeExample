#include <stdio.h>
#include <stdlib.h>
#include "listUtils.h"

int main()
{
	//��������
	classes *cls = initClasses();

	#pragma region ��ӽڵ�
	puts("====================��ӽڵ�======================");
	for (int i = 0; i < 5; i++)
	{
		student *info = createStudent(i + 1, "ѧ��", 1, 20 + i);
		addTo(cls, info);
	}
	showList(cls);
	#pragma endregion

	puts("====================ɾ���ڵ�======================");
	if (deleteAt(cls, 3))
	{
		showList(cls);
	}

	puts("====================���½ڵ�======================");
	student *inf = createStudent(2, "���µ�ѧ��", 0, 18);
	if (updateTo(cls, inf))
	{
		showList(cls);
	}

	system("pause");
	return 0;
}