#include <stdio.h>

//����ṹ����
typedef struct student
{
	int stuId;
	char *name;
	char sex;
	float score;
} s;

//ʾ��3
int avg(s *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		float sc = 0;
		sc += ps->score;
		if (sc < 60)
			count++;
	}
	return count;
}

int main777()
{
	#pragma region �ṹָ��
	//ʾ��������ѧ���ṹ����ṹָ�����
	struct student stu = { 1001, "����", 'M', 82.5 }, *pstu = &stu;
	//���ʳ�Ա����
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,�ɼ�:%f\n", stu.stuId, stu.name, stu.sex == 'M' ? "��" : "Ů", stu.score);
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,�ɼ�:%f\n", (*pstu).stuId, (*pstu).name, (*pstu).sex == 'M' ? "��" : "Ů", (*pstu).score);
	printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,�ɼ�:%f\n", pstu->stuId, pstu->name, pstu->sex == 'M' ? "��" : "Ů", pstu->score);
	#pragma endregion
	puts("");
	#pragma region �ṹ����ָ��
	struct student stuArr[] = {
		{ 1001, "����", 'M', 52.5 },
		{ 1002, "����", 'F', 83.5 },
		{ 1003, "����", 'M', 64.5 },
		{ 1004, "����", 'F', 45.5 },
		{ 1005, "����", 'M', 86.5 }
	}, *parr_stu;
	for (parr_stu = stuArr; parr_stu < stuArr + 5; parr_stu++)
	{
		printf_s("ѧ�ţ�%d,���ƣ�%s,�Ա�%s,�ɼ�:%f\n", parr_stu->stuId, parr_stu->name, parr_stu->sex == 'M' ? "��" : "Ů", parr_stu->score);
	}
	#pragma endregion
	puts("");
	#pragma region �ṹָ����Ϊ��������
	//ʾ��������һ��ѧ����ƽ���ɼ��Ͳ������������ýṹָ�����������������
	parr_stu = stuArr;
	printf_s("����������:%d\n", avg(parr_stu, 5));
	#pragma endregion

	system("pause");
	return 0;
}