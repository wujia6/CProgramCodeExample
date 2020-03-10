#include <stdio.h>
#include <string.h>

void sortAsc(void (*pf)(), char *pc[], int len);
void printfs(char *pc[], int len);

int main666()
{
	#pragma region 指针数组
	//示例：定义指针数组
	int *parr[10];
	//示例1：国家名称按字母顺序排序并输出
	char *countries[] = { "CHINA", "AMERICA", "AUSTRALIA", "FRANCE", "GERMAN" };
	sortAsc(printfs, countries, 5);

	system("pause");
	return 0;
	#pragma endregion
}

//示例1
void sortAsc(void (*pf)(), char *pc[], int len)
{
	//冒泡排序
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (strcmp(pc[i], pc[j]) > 0)
			{
				char *pt = pc[i];
				pc[i] = pc[j];
				pc[j] = pt;
			}
		}
	}
	(*pf)(pc, len);
}

//示例1
void printfs(char *pc[], int len)
{
	for (int i = 0; i < len; i++)
	{
		printf_s("%s\n", pc[i]);
	}
}