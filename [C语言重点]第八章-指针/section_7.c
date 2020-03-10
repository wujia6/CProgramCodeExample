#include <stdio.h>

//����ṹ
typedef struct student
{
	int stuId;
	char *name;
	char sex;
	float score;
} s;

//ʾ��������һ��ѧ����ƽ���ɼ��Ͳ���������
int avg(s *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		//��ƽ���ɼ�
		float sc = 0;
		sc += ps->score;
		if (sc / 5 < 60)
			count++;
	}
	return count;
}

int main()
{
	#pragma region �ṹָ��
	//����ṹ������ָ�����
	s stu = { 1001,"����",0,82.5 }, *pstu = &stu;
	//���ʳ�Ա����
	printf_s("ѧ�ţ�%d,������%s,�Ա�%s,������%f\n", stu.stuId, stu.name, stu.sex == 'F' ? "Ů" : "��", stu.score);
	printf_s("ѧ�ţ�%d,������%s,�Ա�%s,������%f\n", (*pstu).stuId, (*pstu).name, (*pstu).sex == 'F' ? "Ů" : "��", (*pstu).score);
	printf_s("ѧ�ţ�%d,������%s,�Ա�%s,������%f\n", pstu->stuId, pstu->name, pstu->sex == 'F' ? "Ů" : "��", pstu->score);
	#pragma endregion

	puts("");

	#pragma region �ṹ����ָ��
	s stuArr[] = 
	{
		{101,"Zhou ping",'M',45},
		{102,"Zhang ping",'M',62.5},
		{103,"Liou fang",'F',92.5},
		{104,"Cheng ling",'F',87},
		{105,"Wang ming",'M',58}
	}, *p_stu;
	for (p_stu = stuArr; p_stu < stuArr + 5; p_stu++)
	{
		printf_s("ѧ�ţ�%d,������%s,�Ա�%s,������%f\n", p_stu->stuId, p_stu->name, p_stu->sex == 'F' ? "Ů" : "��", p_stu->score);
	}
	#pragma endregion

	puts("");

	#pragma region �ṹָ����Ϊ��������
	p_stu = stuArr;
	printf_s("����������:%d\n", avg(p_stu, 5));
	#pragma endregion
	system("pause");
	return 0;
}

