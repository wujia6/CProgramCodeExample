#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

int main()
{
	#pragma region �༶ָ��ԭ��
	//int p = 10, s = 20,
	//	*p1 = &p,	//ָ�����ͱ�����ַ
	//	**p2 = &p1, //ָ�����ͱ���ָ���ַ
	//	***p3 = &p2;//ָ�����ͱ���ָ���ָ���ַ
	//
	//printf("p3:%#x\n", p3);
	//printf("*p3:%#x,p2:%#x\n", *p3, p2);
	//printf("**p3:%#x,*p2:%#x,p1:%#x\n", **p3, *p2, p1);
	//printf("***p3:%d,**p2:%d,*p1:%d\n", ***p3, **p2, *p1);
	//puts("");
	//**p3 = &s;
	//printf("***p3:%d,**p2:%d,*p1:%d\n", ***p3, **p2, *p1);
	#pragma endregion

	//puts("");

	#pragma region �༶ָ��Ӧ��
	//����ͷ�ڵ�
	list *linked= malloc(sizeof(list));
	linked->len = 0;
	linked->header = NULL;
	//��ӽڵ�
	for (int i = 0; i < 10; i++)
	{
		if (!addNode(linked, i + 1, i + 1 == 1 ? "��Ԫ�ڵ�" : "��ͨ�ڵ�"))
		{
			puts("������ӽڵ㱻�жϡ�");
			break;
		}
	}
	display(linked);
	#pragma endregion

	system("pause");
	return 0;
}