#include <stdio.h>
#include <string.h>

//函数原型
void storAsc(char *arr[], int);

int main666()
{
	#pragma region 指针数组
	//示例：定义指针数组
	int arr[][3] = { 9,8,7, 6,5,4, 3,2,1 },
		*parr[3] = { arr[0], arr[1], arr[2] },
		num = *(parr[1] + 1);
	printf_s("%d\n", num);
	puts("");

	char string[2][10] = { "CHINA", "AMERICA" };
	// 国家名称按字母顺序排序并输出
	char *countries[] = { "CHINA", "AMERICA", "AUSTRALIA", "FRANCE", "GERMAN" };
	storAsc(countries, 5);
	for (int i = 0; i < 5; i++)
	{
		printf_s("%s\n", countries[i]);
	}
	#pragma endregion

	system("pause");
	return 0;
}

//示例1
void storAsc(char *arr[], int len)
{
	//冒泡排序
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = i + 1; j < len; j++)
		{
			if (strcmp(arr[i], arr[j]) > 0)
			{
				char *tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}