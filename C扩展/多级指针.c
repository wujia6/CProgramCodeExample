#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

void funcB(int *tmp)
{
	*tmp = 100;
}

void funcA()
{
	int tmp = 20, *p = &tmp;
	funcB(p);
	printf_s("%d\n", *p);
}

int main0()
{
	#pragma region �༶ָ��ԭ��
	
	/*int p = 10, s = 20,
		*p1 = &p,
		**p2 = &p1,
		***p3 = &p2;
	printf_s("��3��ָ��Ƕȷ��ʸ���ָ�룺p3:%0x,*p3:%0x,**p3:%0x,***p3:%d\n",p3, *p3, **p3, ***p3);
	printf_s("��2��ָ��Ƕȷ��ʸ���ָ�룺&p2:%0x,p2:%0x,*p2:%0x,**p2:%d\n", &p2, p2, *p2, **p2);
	printf_s("��1��ָ��Ƕȷ��ʸ���ָ�룺&p1:%0x,p1:%0x,*p1:%d\n", &p1, p1, *p1);
	puts("");
	*p2 = &s;
	printf_s("p3:%d, p2:%d, p1:%d\n", ***p3, **p2, *p1);*/
	#pragma endregion

	puts("");

	#pragma region ����������ֵ�봫ַ����

	funcA();

	#pragma endregion

	puts("");

	#pragma region �༶ָ��Ӧ��
	
	#pragma endregion

	system("pause");
	return 0;
}