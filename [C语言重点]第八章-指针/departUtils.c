#include <stdio.h>
#include <malloc.h>
#include "departUtils.h"

//初始化部门(头节点)
depart * initDepart(int depId, char *depName)
{
	depart *dep = malloc(sizeof(depart));
	dep->depId = depId;
	dep->depName = depName;
	dep->peoples = 0;
	dep->first = NULL;
	return dep;
}

employee * createEntrys(int empId, char * name, int gender, int age)
{
	employee *emp = malloc(sizeof(employee));
	emp->empId = empId;
	emp->empName = name;
	emp->gender = gender;
	emp->age = age;
	emp->next = NULL;
	return emp;
}

//添加节点
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

void displayAlls(depart *dep)
{
	employee *tmp = dep->first;
	for (int i = 0; i < dep->peoples; i++, tmp=tmp->next)
	{
		printf_s("empId:%d,empName:%s,gender:%s,age:%d\n", tmp->empId, tmp->empName, tmp->gender ? "女" : "男", tmp->age);
	}
}
