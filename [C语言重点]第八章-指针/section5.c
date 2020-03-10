#include <stdio.h>

//函数原型
char *getWeek(int day);
int *getNumber(int(*pf)());
int getMini(int, int);

int main555()
{
	#pragma region 指针函数
	puts("===============指针函数==================");
	int num = 0;
	puts("请输入一周对应的天数：");
	scanf_s("%d", &num);
	if (num < 1 || num > 7)
	{
		//puts("只能输入1-7之间的整数");
		exit(1);	//参数1：代表程序有异常退出,如参数是0就代表正常退出。
	}
	printf_s("%s\n", getWeek(num));
	#pragma endregion

	puts("");

	#pragma region 函数指针
	puts("=================函数指针====================");
	//示例：通过函数指针实现对函数的调用
	int(*pf_getMini)();
	pf_getMini = getMini;
	int mini = (*pf_getMini)(9, 12) + 10;
	printf_s("%d\n", mini);
	//函数指针作为参数
	printf_s("%d\n", getNumber(pf_getMini));
	#pragma endregion

	system("pause");
	return 0;
}

//示例1
char *getWeek(int day)
{
	char *weeks[] =
	{
		"只能输入1-7之间的整数",
		"星期一",
		"星期二",
		"星期三",
		"星期四",
		"星期五",
		"星期六",
		"星期天"
	};
	return day >= 1 && day <= 7 ? weeks[day] : weeks[0];
}

//示例2
int getMini(int x, int y)
{
	return x < y ? x : y;
}

//示例3
int *getNumber(int(*pf)())
{
	int *ptr = (*pf)(5,9);
	return ptr;
}