#include <stdio.h>
#include <malloc.h>
#include "listUtils.h"

#pragma region 双链表函数
classes *initClasses()
{
	classes *cls = (classes *)malloc(sizeof(classes));
	cls->clsId = 1702;
	cls->clsName = "火箭班";
	cls->total = 0;
	cls->first = NULL;
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

student *findBy(classes *cls, int index, int stuId)
{
	if (cls == NULL) return NULL;
	student *inf = cls->first;
	for (int i = 1; i <= cls->total; i++, inf = inf->next)
	{
		if (index == i)
			return inf;
		if (!index && inf->stuId == stuId)
			return inf;
	}
	return NULL;
}

void showList(classes * cls)
{
	student *tmp = cls->first;
	for (int i = 0; i < cls->total; i++, tmp = tmp->next)
	{
		printf_s("stuId:%d,stuName:%s,gender:%s,age:%d\n", tmp->stuId, tmp->stuName, tmp->gender ? "男" : "女", tmp->age);
	}
}

void addTo(classes *cls, student *info)
{
	if (cls == NULL || info == NULL) return;
	if (cls->first == NULL)
	{
		cls->first = info;
		cls->total++;
		return;
	}
	student *tmp = cls->first;
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
	student *curr = findBy(cls, index, 0);
	if (index == 1)		//首元节点
	{
		info->next = curr;
		cls->first = curr->before = info;
	}
	else if (index > 1 && index < cls->total)	//中间节点
	{
		//新节点与前驱节点建立双层链接
		info->before = curr->before;
		curr->before->next = info;
		//新节点与后继节点建立双层链接
		curr->before = info;
		info->next = curr;
	}
	else	//末端节点
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
	student *del = findBy(cls, 0, stuId);
	if (del->before == NULL)	//首元节点
	{
		del->next->before = NULL;
		cls->first = del->next;
	}
	else	//其他节点
	{
		del->next->before = del->before;
		del->before->next = del->next;
	}
	free(del);
	cls->total--;
	return 1;
}

int updateTo(classes *cls, student *info)
{
	if (cls == NULL || info == NULL) return 0;
	student *rep = findBy(cls, 0, info->stuId);
	if (rep == NULL) return 0;
	info->next = rep->next;
	if (rep->before == NULL)	//首元节点
		cls->first = info;
	else
	{
		info->before = rep->before;
		rep->before->next = info;
	}
	free(rep);
	return 1;
}

#pragma endregion