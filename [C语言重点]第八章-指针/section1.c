#include <stdio.h>

int getMax(int *p1, int *p2)
{
	return *p1 > *p2 ? p1 : p2;
}

void maintttt()
{
	#pragma region 指针定义初始化引用
	//1.定义
	int a=10, *p;
	p = &a;
	int b = 20, *ptr = &b;

	//p+sizeof(int)	//x86占2个字节，x64占4个字节

	//2.引用指针变量
	int c = 200, x, *pc = &c;
	x = *pc;

	int i = 10, j = 20, *pa = &i, *pb = &j;
	pa = pb;
	printf_s("%d", *pa);
	puts("");
	int s = 10, k, *ps = &s;
	*ps++; *ps--;
	k = *ps + 10;
	printf_s("%d", k);
	//puts("");
	#pragma endregion

	#pragma region 指针变量作为形参
	int res = getMax(pa, pb);
	printf_s("%x\n", res);
	#pragma endregion

	#pragma region 数组指针（一维数组）
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }, *parr;
	//1.下标法
	for (int i = 0; i < 10; i++)
	{
		printf_s("%d", arr[i]);
	}
	puts("");
	//2.指针法
	for (parr = arr; parr < arr + 10; parr++)
	{
		printf_s("%d", *parr);
	}

	#pragma endregion


	system("pause");
}

