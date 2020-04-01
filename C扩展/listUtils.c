#include <stdio.h>
#include <malloc.h>
#include "listUtils.h"

#pragma region ˫������
classes *initClasses()
{
	classes *cls = (classes *)malloc(sizeof(classes));
	cls->clsId = 1702;
	cls->clsName = "�����";
	cls->total = 0;
	cls->header = NULL;
	return cls;
}

student *createStudent(int stuId, char *stuName, int gender, int age)
{
	student *stu = (student *)malloc(sizeof(student));
	stu->stuId = stuId;
	stu->stuName = stuName;
	stu->gender = gender;
	stu->age = age;
	stu->before = NULL;
	stu->next = NULL;
	return stu;
}

void showList(classes * cls)
{
	student *tmp = cls->header;
	for (int i = 0; i < cls->total; i++, tmp = tmp->next)
	{
		printf_s("stuId:%d,stuName:%s,gender:%s,age:%d\n", tmp->stuId, tmp->stuName, tmp->gender ? "��" : "Ů", tmp->age);
	}
}

void addTo(classes *cls, student *info)
{
	if (cls == NULL || info == NULL) return;
	if (cls->header == NULL)
	{
		cls->header = info;
		cls->total++;
		return;
	}
	student *tmp = cls->header;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	info->before = tmp;
	tmp->next = info;
	cls->total++;
}

int insertTo(classes *cls, int index, student *info)
{
	if (cls == NULL || index == 0 || info == NULL) return 0;
	student *curr = getStudent(cls, index, 0);
	if (index == 1)		//��Ԫ�ڵ�
	{
		info->next = curr;
		cls->header = curr->before = info;
	}
	else if (index > 1 && index < cls->total)	//�м�ڵ�
	{
		//�½ڵ���ǰ���ڵ㽨��˫������
		info->before = curr->before;
		curr->before->next = info;
		//�½ڵ����̽ڵ㽨��˫������
		curr->before = info;
		info->next = curr;
	}
	else	//ĩ�˽ڵ�
	{
		curr->next = info;
		info->before = curr;
	}
	cls->total++;
	return 1;
}

int deleteAt(classes *cls, int stuId)
{
	if (cls == NULL || stuId == 0) return 0;
	student *del = getStudent(cls, 0, stuId);
	if (del->before == NULL)	//��Ԫ�ڵ�
	{
		del->next->before = NULL;
		cls->header = del->next;
	}
	else	//�����ڵ�
	{
		del->next->before = del->before;
		del->before->next = del->next;
	}
	free(del);
	return 1;
}

int updateTo(classes *cls, student *info)
{
	if (cls == NULL || info == NULL) return 0;
	student *replace = getStudent(cls, 0, info->stuId);
	if (replace == NULL) return 0;
	info->next = replace->next;
	if (replace->before == NULL)	//��Ԫ�ڵ�
		cls->header = info;
	else
	{
		info->before = replace->before;
		replace->before->next = info;
	}
	free(replace);
	return 1;
}

student *getStudent(classes *cls, int index, int stuId)
{
	if (cls == NULL) return NULL;
	student *inf = cls->header;
	for (int i = 1; i <= cls->total; i++, inf = inf->next)
	{
		if (index == i)
			return inf;
		if (!index && inf->stuId == stuId)
			return inf;
	}
	return NULL;
}
#pragma endregion