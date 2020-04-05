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

	#pragma region ����ڵ�
	puts("====================����ڵ�======================");
	student *info = createStudent(6, "�����", 1, 19);
	if (insertTo(cls,5,info))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region ���½ڵ�
	puts("====================���½ڵ�======================");
	student *inf = createStudent(2, "����", 1, 19);
	if (updateTo(cls, inf))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region ɾ���ڵ�
	puts("====================ɾ���ڵ�======================");
	if (deleteAt(cls, 4))
	{
		showList(cls);
	}
	#pragma endregion

	system("pause");
	return 0;
}