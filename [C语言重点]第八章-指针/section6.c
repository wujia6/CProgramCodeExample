#include <stdio.h>
#include <string.h>

//����ԭ��
void storAsc(char *arr[], int);

int main666()
{
	#pragma region ָ������
	//ʾ��������ָ������
	int arr[][3] = { 9,8,7, 6,5,4, 3,2,1 },
		*parr[3] = { arr[0], arr[1], arr[2] },
		num = *(parr[1] + 1);
	printf_s("%d\n", num);
	puts("");

	char string[2][10] = { "CHINA", "AMERICA" };
	// �������ư���ĸ˳���������
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

//ʾ��1
void storAsc(char *arr[], int len)
{
	//ð������
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