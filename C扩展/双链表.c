#include <stdio.h>
#include <stdlib.h>
#include "listUtils.h"

int main()
{
	#pragma region ����˫����
	puts("====================����˫����======================");
	//����������ӽڵ�
	classes *cls = initClasses();
	#pragma endregion

	#pragma region ��ӽڵ�
	puts("====================��ӽڵ�======================");
	for (int i = 0; i < 5; i++)
	{
		student *info = createStudent(i + 1, "ѧ��", 1, 20 + i);
		addTo(cls, info);
	}
	showlist(cls);
	#pragma endregion

	#pragma region ����ڵ�
	puts("====================����ڵ�======================");
	student *info = createStudent(6, "�����", 1, 19);
	if (insertTo(cls,5,info))
	{
		showlist(cls);
	}
	#pragma endregion

	system("pause");
	return 0;
}