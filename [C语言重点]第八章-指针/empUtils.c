#include "empUtils.h"
#include <stdio.h>
#include <malloc.h>

depart *initialize(int depId, char *depName)
{
	depart *dep = malloc(sizeof(depart));
	if (dep != NULL)
	{
		//ÊôÐÔ
		dep->depId = depId;
		dep->depName = depName;
		dep->peoples = 0;
		dep->first = NULL;
		//º¯Êý
		dep->findBy = findBy;
		dep->addTo = addTo;
		dep->editTo = editTo;
		dep->removeBy = removeBy;
	}
	return dep;
}

employee * createEntry(int empId, char * empName, int gender, int age)
{
	employee *entry = (employee *)malloc(sizeof(employee));
	entry->empId = empId;
	entry->empName = empName;
	entry->gender = gender;
	entry->age = age;
	entry->next = NULL;
	return entry;
}

void displayAll(depart *dep)
{
	employee *tmp = dep->first;
	while (tmp!=NULL)
	{
		printf_s("depId:%d,depName:%s,gender:%s,age:%d\n", tmp->empId, tmp->empName, tmp->gender ? "Å®" : "ÄÐ", tmp->age);
		tmp = tmp->next;
	}
}

employee *searchBy(depart *dep, int empId)
{
	employee *tmp = dep->first;
	while (tmp)
	{
		if (tmp->empId == empId)
			return tmp;
		tmp = tmp->next;
	}
	return NULL;
}

void appendTo(depart *dep, employee *entry)
{
	employee *tmp = dep->first;
	if (tmp != NULL)
	{
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		tmp->next = entry;
	}
	else
		dep->first = entry;
	dep->peoples++;
}

int insertAt(int index, employee * entry)
{
	return 0;
}

int removeBy(depart *dep, int empId)
{
	employee *front = searchBy(dep, empId - 1),
		*del = front->next;
	if (del == NULL)
		return 0;
	front->next = del->next;
	free(del);
	return 1;
}

int editTo(depart *dep, employee * emp)
{
	employee *front = searchBy(dep, emp->empId - 1),
		*old = front->next;
	if (old == NULL)
		return 0;
	emp->next = old->next;
	front->next = emp;
	free(old);
	return 1;
}
