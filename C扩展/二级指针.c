#include <stdio.h>
#include <malloc.h>

//��ֵ����ַ
void func_B(int *tmp)
{
	printf_s("%#x\n", tmp);
	*tmp = 1;
}

void func_A()
{
	int tmp = 0,*p=&tmp;
	printf_s("%#x\n", p);
	func_B(p);
	printf_s("%d\n", *p);
}

typedef struct list_node
{
	int key;
	char *message;
	struct list_node *next;
} node;

typedef struct list_header
{
	node *herder;
} list;

int insertNode(list *plst, node *pnode)
{
	if (plst==NULL)
		return 0;
	node **curr = &plst->herder;
	while (*curr != NULL && (*curr)->key < pnode->key)
	{
		*curr = (*curr)->next;
	}
	pnode->next = (*curr)->next;
	*curr = pnode;
}

int main1111()
{
	#pragma region ����ָ��ԭ��
	int p = 10, s = 20,
		*p1 = &p,
		**p2 = &p1,
		***p3 = &p2;
	/*printf_s("p3:%#x,&p3:%#x\n", p3,&p3);
	puts("");
	printf_s("*p3:%#x,p2:%#x\n", *p3,p2);
	puts("");
	printf_s("**p3:%#x,*p2:%#x,p1:%#x\n", **p3,*p2,p1);
	puts("");
	printf_s("***p3:%d,**p2:%d,*p1:%d\n", ***p3,**p2,*p1);
	puts("");
	*p2 = &s;
	printf_s("***p3:%d,**p2:%d,*p1:%d\n", ***p3, **p2, *p1);

	//��ֵ���á��Ե�ַ����
	//**p3==&p2
	printf_s("*p3:%#x,p2:%#x\n", **p3, p1);*/
	#pragma endregion

	#pragma region ��ֵ�봫ַ
	func_A();
	#pragma endregion

	#pragma region �༶ָ��Ӧ��
	//��������
	list *plst = malloc(sizeof(list));
	plst->herder = NULL;
	
	for (int i = 0; i < 5; i++)
	{
		//�����ڵ�
		node *pnode = malloc(sizeof(node));
		pnode->key = i + 1;
		pnode->message = i + 1 == 1 ? "��Ԫ�ڵ�" : "��ͨ�ڵ�";
		pnode->next = NULL;
		insertNode(plst, pnode);
	}
	#pragma endregion


	system("pause");
	return 0;
}