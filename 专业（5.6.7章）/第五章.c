#include <stdio.h>
#include <string.h>

#define LEN 10
#define P printf_s
#define D "%d\n"
#define C "%c\n"
#define F "%f\n"
#define S "%s\n"

void msymain()
{
	//数组
	//1.定义数组
	//数组下标从0开始0-9
	//int x = 2, j = 3;
	////初始化
	//int arr[LEN] = { 0,1,2,3,4,5,6,7,8,9 };
	//float arr1[LEN] = { 1.1,2.2,3.3,4.4,5.5 };
	//int arr2[] = { 1,2,3,4,5 };

	//for (int i = 0; i < LEN; i++)
	//{
	//	if (i>=4 && i<=7)
	//	{
	//		P(D, arr[i]);
	//	}
	//}

	//二维数组
	//int arr[2][3] = { {1,2,3},{4,5,6} };
	//int arr1[2][3] = { 1,2,3,4,5,6 };
	//int arr2[][3] = { 1,2,3,4,5,6,7,8,9 };
	////访问
	//P(D, arr2[2][0]);

	/*for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			P(D, arr[i][j]);
		}
	}*/

	//字符数组
	char ch[10] = { 'C',' ','p','r','o','g','r','a','m' };
	char ch1[] = { 'C',' ','p','r','o','g','r','a','m' };
	char str1[] = { "C Language" };
	char str2[] = "C program";
	//puts(str2);

	int len = strlen(str2);
	P(D, len);
	//strcpy(str1, str2);

	system("pause");
}