#include <stdio.h>
#include <string.h>

//示例1
int findCH(char *pstr)
{
	for (int i = 0; i < strlen(pstr); i++)
	{
		if (pstr[i] == 'k')
			return 1;
	}
	return 0;
}

//示例2
void formatter()
{
	char *pd = "%d\n", *pc = "%c\n", *ps = "%s\n", *px = "%x\n";
	printf_s(pd, 10);
	printf_s(pc, 'g');
	printf_s(ps, "Hello World");
	//printf_s(px, 10799772);
}

//示例3
void strCopy(char *pstr1, char *pstr2)
{
	while (*pstr2++ = *pstr1++);
}

void maindddd()
{
	//1.字符串指针定义
	char str[] = "HongXiang School";
	char *string1 = "C Program Diesgn", *string2="";

	for (int i = 0; i < strlen(str); i++)
	{
		printf_s("%c", string1[i]);
	}
	puts("");
	//puts(string);

	//2.修改字符串指针
	//str[4] = 'k';
	//puts(str);

	//字符串指针代码示例
	//【VS代码示例】在输入的字符串中查找有无‘k’字符。
	//【VS代码示例】将指针变量指向一个格式字符串，并printf函数中使用格式字符串。
	//【VS代码示例】要求把一个字符串的内容复制到另一个字符串中，字符串指针作为函数参数使用(不能使用sring.h函数库)。*/
	//调用示例1
	if (findCH(string1))
		puts("包含字符'k'");
	else
		puts("不包含字符'k'");

	//调用示例2
	formatter();

	//调用示例3
	strCopy(string1, string2);
	puts(string2);
	system("pause");
}

