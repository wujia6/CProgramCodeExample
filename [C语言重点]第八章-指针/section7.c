#include <stdio.h>

typedef struct studentInfo
{
	int stuId;
	char *name;
	char gender;
	float score;
} student;

void avg(student *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		 if (ps->score < 60)
			 count++;
	}
	printf_s("������������%d\n", count);
}

int main777()
{
	#pragma region �ṹָ��
	//����ṹָ�����
	student stu = { 1001,"����",'M',62.5 },
		*ps = &stu;
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,������%f\n", stu.stuId, stu.name, stu.gender == 'M' ? "��" : "Ů", stu.score);
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,������%f\n", (*ps).stuId, (*ps).name, (*ps).gender == 'M' ? "��" : "Ů", (*ps).score);
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,������%f\n", ps->stuId, ps->name, ps->gender == 'M' ? "��" : "Ů", ps->score);
	#pragma endregion

	puts("");

	#pragma region �ṹ����ָ��
	student stuArr[]=
	{
		{ 1001,"����",'M',82.5 },
		{ 1002,"����",'F',72.5 },
		{ 1003,"����",'M',82.5 },
		{ 1004,"����",'F',92.5 },
		{ 1005,"����",'M',62.5 }
	}, *pstu = stuArr;
	for (pstu = stuArr; pstu < stuArr + 5; pstu++)
	{
		printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,������%f\n", pstu->stuId, pstu->name, pstu->gender == 'M' ? "��" : "Ů", pstu->score);
	}
	#pragma endregion

	puts("");

	#pragma region �ṹָ����Ϊ��������
	//����һ��ѧ����ƽ���ɼ��Ͳ������������ýṹָ�����������������
	avg(pstu, 5);
	#pragma endregion

	system("pause");
	return 0;
}