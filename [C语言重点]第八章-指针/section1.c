#include <stdio.h>

int getMax(int *pa, int *pb)
{
	return *pa > *pb ? pa : pb;
}

void mainss()
{
	//1.定义指针1
	int a = 10, *pa;
	pa = &a;
	//2.定义指针2
	int b = 20, *pb = &b;
	//3.引用指针1
	int c = 200, x, *pc = &c;
	x = *pc;
	//4.改变指针
	int i = 'a', j = 'b', *pi = &i, *pj = &j;
	pi = pj;	//改变指向
	*pi = *pj;	//改变值
	//5.表达式
	int s = 10, k, *ps = &s;
	*ps++; *ps--;
	k = *ps + 10;
	//指针作为函数参数
	int num = getMax(pa, pb);
	//printf_s("%x", num);
	//数组指针
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 }, *parr;
	//下标法
	/*for (int i = 0; i < 10; i++)
	{
		pirntf_s("%d", arr[i]);
	}*/
	//指针法
	//int arr1 = *(parr + 1);
	for (parr = arr; parr < arr + 10; parr++)
	{
		printf_s("值：%d,地址：%x\n", *parr, parr);
	}
	system("pause");
}

