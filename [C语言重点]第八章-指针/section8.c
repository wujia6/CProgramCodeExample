#include <stdio.h>
#include "utils.h"

int main()
{
	node *pHead;	//����ͷָ��

	#pragma region ��������
	//ʾ������������ 0��ʾ����ͷ�ڵ�
	pHead = createNode(0, NULL);
	#pragma endregion

	#pragma region ׷�ӽڵ�
	//������׷��10���ڵ�
	for (int i = 1; i <= 10; i++)
	{
		appendNode(pHead, createNode(i, "�ڵ� " + i));
	}
	#pragma endregion

	#pragma region ����ڵ�
	node newNode = { 11,"�²���ڵ�",NULL }, *p_insert = &newNode;
	insertNode(pHead, 9, p_insert);
	#pragma endregion

	#pragma region ���ҽڵ�
	//ʾ��������������Ϊ5�Ľڵ�
	node *p_find = findNode(pHead, 5);
	p_find == NULL ? puts("�����ڸýڵ�") : printf_s("id:%d,msg:%s\n", p_find->index, p_find->message);
	free(p_find);
	#pragma endregion

	#pragma region ɾ���ڵ�
	//ʾ����ɾ���ڵ�
	if(removeNode(pHead, 9))
		puts("��ʾ����ɾ��ָ���ڵ�");
	#pragma endregion
	
	#pragma region ���½ڵ�
	updateNode(pHead, 7, "�ղ��޸ĵĽڵ�");
	#pragma endregion

	#pragma region ��̬�ڴ����
	//ʾ�������붯̬�ڴ�
	student *ps = (student*)malloc(sizeof(student));
	ps->stuId = 1001;
	ps->stuName = "����";
	ps->stuGender = 'M';
	ps->stuScore = 62.5;
	printf_s("ѧ�ţ�%d,������%s,�Ա�%s,�ɼ���%f\n", ps->stuId, ps->stuName, ps->stuGender == 'M' ? "��" : "Ů", ps->stuScore);
	ps = (student*)calloc(2, sizeof(student));	//�����ڴ泤��2
	free(ps);	//���
	#pragma endregion

	system("pause");
	return 0;
}


