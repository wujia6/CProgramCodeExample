#include <stdio.h>

//����ԭ��
char *getWeek(int day);
int *getNumber(int(*pf)());
int getMini(int, int);

int main555()
{
	#pragma region ָ�뺯��
	puts("===============ָ�뺯��==================");
	int num = 0;
	puts("������һ�ܶ�Ӧ��������");
	scanf_s("%d", &num);
	if (num < 1 || num > 7)
	{
		//puts("ֻ������1-7֮�������");
		exit(1);	//����1������������쳣�˳�,�������0�ʹ��������˳���
	}
	printf_s("%s\n", getWeek(num));
	#pragma endregion

	puts("");

	#pragma region ����ָ��
	puts("=================����ָ��====================");
	//ʾ����ͨ������ָ��ʵ�ֶԺ����ĵ���
	int(*pf_getMini)();
	pf_getMini = getMini;
	int mini = (*pf_getMini)(9, 12) + 10;
	printf_s("%d\n", mini);
	//����ָ����Ϊ����
	printf_s("%d\n", getNumber(pf_getMini));
	#pragma endregion

	system("pause");
	return 0;
}

//ʾ��1
char *getWeek(int day)
{
	char *weeks[] =
	{
		"ֻ������1-7֮�������",
		"����һ",
		"���ڶ�",
		"������",
		"������",
		"������",
		"������",
		"������"
	};
	return day >= 1 && day <= 7 ? weeks[day] : weeks[0];
}

//ʾ��2
int getMini(int x, int y)
{
	return x < y ? x : y;
}

//ʾ��3
int *getNumber(int(*pf)())
{
	int *ptr = (*pf)(5,9);
	return ptr;
}