#include <stdio.h>
#include "utils.h"

int main888()
{
	node *pHead;	//����ͷָ��

	#pragma region ��������
	pHead = createNode(1, "��Ԫ�ڵ�");
	//printf_s("key:%d��message:%s\n", pHead->key, pHead->message);
	#pragma endregion

	puts("");

	#pragma region ׷�ӽڵ�
	for (int i = 2; i <= 10; i++)
	{
		node *pLink = createNode(i, "��ͨ�ڵ�");
		appendNode(pHead, pLink);
	}
	displayNodes(pHead);
	#pragma endregion

	puts("");

	#pragma region ����ڵ�
	node *pNode = createNode(11, "�����ĩ�˽ڵ�");
	pHead = insertNode(pHead, pNode);
	displayNodes(pHead);
	#pragma endregion

	puts("");

	#pragma region ɾ���ڵ�
	/*if (removeNode(pHead, 11))
		puts("ɾ���ɹ�");
	else
		puts("ɾ��ʧ��");
	displayNodes(pHead);*/
	#pragma endregion

	puts("");

	#pragma region ���½ڵ�
	/*printf_s("%s\n", updateNode(pHead, 5, "���µ���ͨ�ڵ�") ? "���³ɹ�" : "����ʧ��");
	displayNodes(pHead);*/
	#pragma endregion

	system("pause");
	return 0;
}