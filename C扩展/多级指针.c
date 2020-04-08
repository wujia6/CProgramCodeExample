#include <stdio.h>
#include <malloc.h>
#include "myUtils.h"

void funcB(int tmp)
{
	tmp = 100;
}

void funcA()
{
	int tmp = 20, *p = &tmp;
	funcB(tmp);
	printf_s("%d\n", tmp);
}

int main1()
{
	#pragma region 多级指针原理
	
	/*int p = 10, s = 20,
		*p1 = &p,
		**p2 = &p1,
		***p3 = &p2;
	printf_s("从3级指针角度访问各级指针：p3:%0x,*p3:%0x,**p3:%0x,***p3:%d\n",p3, *p3, **p3, ***p3);
	printf_s("从2级指针角度访问各级指针：&p2:%0x,p2:%0x,*p2:%0x,**p2:%d\n", &p2, p2, *p2, **p2);
	printf_s("从1级指针角度访问各级指针：&p1:%0x,p1:%0x,*p1:%d\n", &p1, p1, *p1);
	puts("");
	*p2 = &s;
	printf_s("p3:%d, p2:%d, p1:%d\n", ***p3, **p2, *p1);*/
	#pragma endregion

	puts("");

	#pragma region 函数参数传值与传址区别

	funcA();

	#pragma endregion

	puts("");

	#pragma region 多级指针应用
	
	#pragma endregion

	system("pause");
	return 0;
}