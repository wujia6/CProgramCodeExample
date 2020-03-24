#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

int main()
{
	#pragma region 多级指针原理
	//int p = 10, s = 20,
	//	*p1 = &p,	//指向整型变量地址
	//	**p2 = &p1, //指向整型变量指针地址
	//	***p3 = &p2;//指向整型变量指针的指针地址
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

	#pragma region 多级指针应用
	//创建头节点
	list *linked= malloc(sizeof(list));
	linked->len = 0;
	linked->header = NULL;
	//添加节点
	for (int i = 0; i < 10; i++)
	{
		if (!addNode(linked, i + 1, i + 1 == 1 ? "首元节点" : "普通节点"))
		{
			puts("错误，添加节点被中断。");
			break;
		}
	}
	display(linked);
	#pragma endregion

	system("pause");
	return 0;
}