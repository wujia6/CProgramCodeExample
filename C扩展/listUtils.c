#include <stdio.h>
#include <malloc.h>
#include "listUtils.h"

#pragma region 双链表函数
student * findBy(classes * cls, int index, int stuId)
{
	if (cls == NULL)
		return NULL;
	if (index > cls->total)
		index = cls->total;
	student *inf = cls->first;
	for (int i = 1; i <= cls->total; i++, inf=inf->next)
	{
		if (index > 0 && index == i)
			return inf;
		if (inf->stuId == stuId)
			return inf;
	}
	return NULL;
}

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

int updateTo(classes * cls, student * info)
{
	if (cls==NULL || info==NULL)
		return 0;
	student *rep = findBy(cls, 0, info->stuId);
	if (rep->before == NULL)	//更新首元节点
	{
		info->next = rep->next;
		rep->next->before = info;
		cls->first = info;
	}
	else
	{
		//新节点与后继节点建立双链接
		info->next = rep->next;
		rep->next->before = info;
		//新节点与前驱节点建立双链接
		info->before = rep->before;
		rep->before->next = info;
	}
	free(rep);
	return 1;
}

void showList(classes * cls)
{
	student *tmp = cls->first;
	for (int i = 1; i <= cls->total; i++, tmp = tmp->next)
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

int insertTo(classes * cls, int index, student * info)
{
	if (cls == NULL || index == 0 || info == NULL) return 0;
	student *curr = findBy(cls, index, 0);
	if (index==1)
	{
		//头插
		info->next = curr;
		cls->first = curr->before = info;
	}
	else if (index > 1 && index <= cls->total)
	{
		//新节点与前驱节点建立链接
		info->before = curr->before;
		curr->before->next = info;
		//新节点与后继节点建立链接
		info->next = curr;
		curr->before = info;
	}
	else
	{
		curr->next = info;
		info->before = curr;
	}
	cls->total++;
	return 1;
}

int deleteAt(classes * cls, int stuId)
{
	if (cls == NULL || stuId <= 0)
		return 0;
	student *del = findBy(cls, 0, stuId);
	if (del->before == NULL)		//判断是否删除首元节点
	{
		del->next->before = NULL;
		cls->first = del->next;
	}
	else	//删除其他节点
	{
		del->before->next = del->next;
		del->next->before = del->before;
	}
	free(del);
	cls->total--;
	return 1;
}
#pragma endregion