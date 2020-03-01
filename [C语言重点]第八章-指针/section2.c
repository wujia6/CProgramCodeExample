#include <stdio.h>

void mainwww()
{
	#pragma region 基础知识
	//1.数组首地址
	int arr[3][4] = { { 1,2,3,4 },{5,6,7,8},{9,10,11,12} }, *parr;
	printf_s("0行0列元素地址：%x\n0行地址：%x\n首地址：%x\n", &arr[0][0], &arr[0], arr);

	//2.二维数组各行首地址 arrB+i == *arrB+i
	printf_s("0行首地址：%x\n1行首地址：%x\n2行首地址：%x\n", arr, arr + 1, arr + 2);
	puts("");
	printf_s("0行首地址：%x\n1行首地址：%x\n2行首地址：%x\n", *(arr), *(arr + 1), *(arr + 2));

	//3.取二维数组元素值
	printf_s("%d\n", *(*arr + 2));	//获取3
	printf_s("%d\n", *(*(arr + 2) + 1));	//获取10

	//4.下标降维法
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int value1 = *(*(arr + i) + j);	//标准方式
			int value2 = *(arr[i] + j);	//降维方式
			printf_s("地址：%x\n值：%d\n", arr + i + j, value1);
		}
	}

	//5.指针降维
	for (parr = arr; parr < arr[0] + 12; parr++)
	{
		printf_s("地址：%x\n值：%d\n", parr, *parr);
	}
	#pragma endregion

	#pragma region 多维数组指针（行指针）
	int scores[][4] = { 70, 77, 80, 85, 58, 64, 79, 80, 88, 72, 92, 96 }, (*prow)[4], *pcol;
	//1.输出总分与平均分
	for (prow = scores; prow < scores + 3; prow++)
	{
		int total = (*prow)[0] + (*prow)[1] + (*prow)[2] + (*prow)[3];
		printf("总分：%d，平均分：%d\n", total, total / 4);
	}

	//2.找出每行的最大值并输出。
	for (prow = scores; prow < scores + 3; prow++)
	{
		int max = (*prow)[0];
		for (pcol = (*prow) + 1; pcol < (*prow) + 4; pcol++)
		{
			if (*pcol > max)
				max = *pcol;
		}
		printf_s("%d\n", max);
	}
	#pragma endregion

	system("pause");
}