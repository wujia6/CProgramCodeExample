#include <stdio.h>
#include <malloc.h>
#include "utils.h"

#pragma region �������������
//��ʼ������(ͷ�ڵ�)
depart * initDepart(int depId, char *depName)
{
	depart *dep = malloc(sizeof(depart));
	dep->depId = depId;
	dep->depName = depName;
	dep->peoples = 0;
	dep->first = NULL;
	//ָ��������Ϊ
	dep->pf_append = appendAt;
	dep->pf_edtiTo = editTo;
	return dep;
}

//����Ա���ڵ�
employee * createEntrys(int empId, char * name, int gender, int age)
{
	employee *emp = malloc(sizeof(employee));
	emp->empId = empId;
	emp->empName = name;
	emp->gender = gender;
	emp->age = age;
	emp->prev = NULL;
	emp->next = NULL;

	emp->pf_say = say;
	return emp;
}

void say(char *content)
{
	puts(content);
}

//��ӽڵ�
void appendAt(depart * dep, employee * entry)
{
	employee *emp = dep->first;
	if (emp != NULL)
	{
		while (emp->next != NULL)
		{
			emp = emp->next;
		}
		emp->next = entry;
	}
	else
		dep->first = entry;
	dep->peoples++;
}

//�༭Ա���ڵ�
int editTo(depart * dep, employee * entry)
{
	employee *front = searchBy(dep, entry->empId),
		*old=front->next;
	if (old==NULL)
		return 0;
	entry->next = old->next;
	front->next = entry;
	free(old);
	return 1;
}

//��ӡ����
void displayAlls(depart *dep)
{
	employee *tmp = dep->first;
	for (int i = 0; i < dep->peoples; i++, tmp = tmp->next)
	{
		printf_s("empId:%d,empName:%s,gender:%s,age:%d\n", tmp->empId, tmp->empName, tmp->gender ? "Ů" : "��", tmp->age);
	}
}

//����
employee *searchBy(depart * dep, int index)
{
	if (dep == NULL)
		return NULL;
	employee *emp = dep->first;
	for (int i = 1; i <= dep->peoples; i++, emp = emp->next)
	{
		if (index == i)
			return emp;
	}
	return NULL;
}

//����ڵ�
int insertAt(depart *dep, int index, employee *entry)
{
	//1.�жϲ���λ��
	//2.����
	if (dep==NULL)
		return 0;
	else if (index == 1)	//���뵽ͷ��
	{
		entry->next = dep->first;
		dep->first = entry;
	}
	else if (index > 1 && index < dep->peoples)	//���뵽�м�
	{
		employee *before = searchBy(dep, index - 1);
		entry->next = before->next;
		before->next = entry;
	}
	else	//���뵽ĩ��
	{
		employee *last = searchBy(dep, dep->peoples);
		last->next = entry;
	}
	return 1;
}

//ɾ���ڵ�
int removeBy(depart *dep, int empId)
{
	if (dep==NULL)
		return 0;
	employee *del, *tmp = dep->first;
	while (tmp->next)
	{
		if (tmp->next->empId == empId)
			break;
		tmp = tmp->next;
	}
	del = tmp->next;
	tmp->next = del->next;
	free(del);
	return 1;
}
#pragma endregion

#pragma region ˫�����������
void addTo(classes *cls, student *info)
{
	if (cls==NULL || stuInfo==NULL)
		return;
	student *tmp = cls->header;
	while (tmp)
		tmp = tmp->next;
	if (tmp!=NULL)
		stuInfo->before = tmp;
	tmp->next = stuInfo;
	cls->total++;
}

int insertTo(classes *cls, int index, student *info)
{
	if (cls==NULL || info==NULL) return 0;
	student *ps = getStudent(cls, index, 0);
	if (index == 1)	//��Ԫ�ڵ�
	{
		info->next = ps;
		cls->header = info;
	}
	else if (index > 1 && index < cls->total)	//�м�ڵ�
	{
		info->next = ps;
		info->before = ps->before;
		ps->before = info;
	}
	else	//ĩ�˽ڵ�
	{
		ps->next = info;
		info->before = ps;
	}
	return 1;
}

int deleteAt(classes *cls, int stuId)
{
	if (cls == NULL) return 0;
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
	if(cls==NULL || info==NULL) return 0;
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

void showlist(classes * cls)
{
	student *tmp = cls->header;
	for (int i = 0; i < cls->total; i++, tmp = tmp->next)
	{
		printf_s("stuId:%d,stuName:%s,gender:%s,age:%d\n", tmp->stuId, tmp->stuName, tmp->gender ? "��" : "Ů", tmp->age);
	}
}

student *getStudent(classes *cls, int index, int stuId)
{
	if (cls == NULL)
		return NULL;
	student *inf = cls->header;
	for (int i = 0; i < cls->total; i++, inf = inf->next)
	{
		if (index == i)
			return inf;
		if (!index && inf->stuId == stuId)
			return inf;
	}
	return NULL;
}

classes *initClass()
{
	classes *cls = (classes *)malloc(sizeof(classes));
	cls->clsId = 1702;
	cls->clsName = "�����";
	cls->total = 0;
	cls->header = NULL;
	return cls;
}

student *initStudent(int stuId, char *stuName, int gender, int age)
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
#pragma endregion