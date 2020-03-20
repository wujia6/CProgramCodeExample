#include <stdio.h>
#include <malloc.h>
#include <string.h>

//����ڵ�
typedef struct node
{
	int key;    //�����򣨴�Ź����ýṹ��Ҫ�����ݣ���������������
	char *name;
	float data;
	struct node *next; //ָ���򣨱�����ͬ���ͣ������һ�ڵ��׵�ַ��
} node;

//�����ڵ�
//@param index�ڵ�������
//@param name�ڵ�����
//@param data�ڵ�����
//@Return *ptr node
node *createNodes(int index, char *name, float data)
{
	node *pNode = (node*)malloc(sizeof(node));	//���붯̬�ڴ�
	memset(pNode, 0, sizeof(node));	//���������
	pNode->key = index;
	pNode->name = name;
	pNode->data = data;
	pNode->next = NULL;
	return pNode;
}

int main()
{
	#pragma region ���붯̬�ڴ�
	//1.malloc����
	//int *ptr = (int *)malloc(sizeof(int));
	//*ptr = 10;
	//printf_s("%d\n", *ptr);
	////2.�ͷ��ڴ�ռ�
	//printf_s("%s\n", "�����ͷ�ptr�ڴ�");
	//free(ptr);
	//printf_s("%d\n", *ptr);
	#pragma endregion

	#pragma region ����ڵ�
	//1.ͷ�ڵ�
	//2.ͷָ��
	//3.��Ԫ�ڵ�
	//4.ǰ���ڵ�		
	//5.��̽ڵ�
	#pragma endregion

	#pragma region ��������
	//����ͷָ�벢ָ����Ԫ�ڵ�
	node *pHead = createNodes(1, "��Ԫ�ڵ�", 100.2);
	node *tmp = pHead;		//��ǰ�ڵ�ָ��
	for (int i = 2; i <= 10; i++)
	{
		node *pNode = createNodes(i, "��ͨ�ڵ�", 100.2 + i);
		tmp->next = pNode;
		tmp = tmp->next;
	}

	tmp = pHead;

	//��������
	while (tmp != NULL)
	{
		printf_s("key:%d,name:%s,data:%f\n", tmp->key, tmp->name, tmp->data);
		tmp = tmp->next;
	}
	#pragma endregion

	system("pause");
	return 0;
}