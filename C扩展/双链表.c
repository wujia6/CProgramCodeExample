#include <stdio.h>
#include <stdlib.h>
#include "listUtils.h"

int main00()
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
	if (insertTo(cls,6,info))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region ���½ڵ�
	puts("====================���½ڵ�======================");
	student *entry = createStudent(1, "����ѧ��", 0, 18);
	if (updateTo(cls,entry))
	{
		showList(cls);
	}
	#pragma endregion

	#pragma region ɾ���ڵ�
	char *msg = deleteAt(cls,5) ? "ɾ���ɹ�" : "�ڵ㲻����";
	puts(msg);
	puts("");
	showList(cls);
	#pragma endregion

	system("pause");
	return 0;
}