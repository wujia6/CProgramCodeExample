#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

int main()
{
	//����ͷ�ڵ��ڴ棬����ͷָ��
	list *lst = malloc(sizeof(list));
	lst->len = 0;
	lst->first = NULL;
	for (int i = 1; i <= 3; i++)
	{
		if (!addNode(lst, i, i == 1 ? "��Ԫ�ڵ�" : "��ͨ�ڵ�"))
		{
			printf_s("������ %d ���ڵ����", i);
			break;
		}	
	}
	ptr_display(lst);
	puts("");
	node *entry = createNode(1, "��Ԫ�ڵ�");
	if (insertNode(lst, 1, entry))
	{
		ptr_display(lst);
	}
	system("pause");
	return 0;
}