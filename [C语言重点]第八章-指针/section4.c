#include <stdio.h>

//��������ԭ��
char *getWeekDay(int);
int getMaxNumber(int, int);

int main_section4()
{
	#pragma region ָ�뺯��
	puts("===================ָ�뺯��=======================");
	//ʾ����ͨ��ָ�뺯��������һ��1-7֮��������������Ӧ������
	int num = 0;
	puts("����һ�ܶ�Ӧ��������");
	scanf_s("%d", &num);
	if (num < 1)
		exit(1);
	printf_s("%s\n", getWeekDay(num));
	#pragma endregion

	puts("");

	#pragma region ����ָ��
	puts("===================����ָ��=======================");
	//ʾ����ͨ������ָ��ʵ�ֶԺ����ĵ���
	int x, y, max, (*pmax)();
	pmax = getMaxNumber;
	puts("input two numbers:");
	scanf_s("%d,%d", &x, &y);
	max = (*pmax)(x, y);
	printf_s("%d\n", max);
	#pragma endregion

	system("pause");
	return 0;
}

//ʾ��1
char *getWeekDay(int day)
{
	char *weeks[] =
	{
		"���ڱ�����1-7֮��",
		"����һ",
		"���ڶ�",
		"������",
		"������",
		"������",
		"������",
		"������"
	};
	return day < 1 || day > 7 ? weeks[0] : weeks[day];
}

//ʾ��2
int getMaxNumber(int x, int y)
{
	return x > y ? x : y;
}