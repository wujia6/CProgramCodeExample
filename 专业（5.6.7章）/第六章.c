#include <stdio.h>
//函数原型
//int getMax(int, int);
//全局动态变量
int x = 12;
//全局静态变量
static int all;

//程序入口
void main()
{
	int arg1 = 4, arg2 = 7;
	int res = getMax(arg1, arg2); //调用时传递实际参数
	printf_s("%d\n", res);
	printf_s("%d\n", res);
	all + 10;
	system("pause");
}

//找出最大数
int getMax(int arg1, int arg2)	//只是形式参数
{
	return arg1 > arg2 ? arg1 : arg2;
}

void getNull()
{
	//do some thing
}