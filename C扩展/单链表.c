#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

int main()
{
	//申请头节点内存，创建头指针
	list *lst = malloc(sizeof(list));
	lst->len = 0;
	lst->first = NULL;
	for (int i = 1; i <= 3; i++)
	{
		if (!addNode(lst, i, i == 1 ? "首元节点" : "普通节点"))
		{
			printf_s("创建第 %d 个节点错误", i);
			break;
		}	
	}
	ptr_display(lst);
	puts("");
	node *entry = createNode(1, "首元节点");
	if (insertNode(lst, 1, entry))
	{
		ptr_display(lst);
	}
	system("pause");
	return 0;
}