#include <stdio.h>

int getMax(int *pa, int *pb)
{
	return *pa > *pb ? pa : pb;
}

void mainss()
{
	//1.����ָ��1
	int a = 10, *pa;
	pa = &a;
	//2.����ָ��2
	int b = 20, *pb = &b;
	//3.����ָ��1
	int c = 200, x, *pc = &c;
	x = *pc;
	//4.�ı�ָ��
	int i = 'a', j = 'b', *pi = &i, *pj = &j;
	pi = pj;	//�ı�ָ��
	*pi = *pj;	//�ı�ֵ
	//5.���ʽ
	int s = 10, k, *ps = &s;
	*ps++; *ps--;
	k = *ps + 10;
	//ָ����Ϊ��������
	int num = getMax(pa, pb);
	//printf_s("%x", num);
	//����ָ��
	int arr[10] = { 0,1,2,3,4,5,6,7,8,9 }, *parr;
	//�±귨
	/*for (int i = 0; i < 10; i++)
	{
		pirntf_s("%d", arr[i]);
	}*/
	//ָ�뷨
	//int arr1 = *(parr + 1);
	for (parr = arr; parr < arr + 10; parr++)
	{
		printf_s("ֵ��%d,��ַ��%x\n", *parr, parr);
	}
	system("pause");
}

