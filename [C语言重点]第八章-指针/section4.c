#include <stdio.h>

//声明函数原型
char *getWeekDay(int);
int getMaxNumber(int, int);

int main_section4()
{
	#pragma region 指针函数
	puts("===================指针函数=======================");
	//示例：通过指针函数，输入一个1-7之间的整数，输出对应星期名
	int num = 0;
	puts("输入一周对应的天数：");
	scanf_s("%d", &num);
	if (num < 1)
		exit(1);
	printf_s("%s\n", getWeekDay(num));
	#pragma endregion

	puts("");

	#pragma region 函数指针
	puts("===================函数指针=======================");
	//示例：通过函数指针实现对函数的调用
	int x, y, max, (*pmax)();
	pmax = getMaxNumber;
	puts("input two numbers:");
	scanf_s("%d,%d", &x, &y);
	max = (*pmax)(x, y);
	printf_s("%d\n", max);
	#pragma endregion

	system("pause");
	return 0;
}

//示例1
char *getWeekDay(int day)
{
	char *weeks[] =
	{
		"日期必须在1-7之间",
		"星期一",
		"星期二",
		"星期三",
		"星期四",
		"星期五",
		"星期六",
		"星期天"
	};
	return day < 1 || day > 7 ? weeks[0] : weeks[day];
}

//示例2
int getMaxNumber(int x, int y)
{
	return x > y ? x : y;
}