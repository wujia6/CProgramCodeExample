#include <stdio.h>

void main()
{
	#pragma region ����֪ʶ
	//1.�����׵�ַ
	int arr[3][4] = { { 1,2,3,4 },{5,6,7,8},{9,10,11,12} }, *parr;
	printf_s("0��0��Ԫ�ص�ַ��%x\n0�е�ַ��%x\n�׵�ַ��%x\n", &arr[0][0], &arr[0], arr);

	//2.��ά��������׵�ַ arrB+i == *arrB+i
	printf_s("0���׵�ַ��%x\n1���׵�ַ��%x\n2���׵�ַ��%x\n", arr, arr + 1, arr + 2);
	puts("");
	printf_s("0���׵�ַ��%x\n1���׵�ַ��%x\n2���׵�ַ��%x\n", *(arr), *(arr + 1), *(arr + 2));

	//3.ȡ��ά����Ԫ��ֵ
	printf_s("%d\n", *(*arr + 2));	//��ȡ3
	printf_s("%d\n", *(*(arr + 2) + 1));	//��ȡ10

	//4.�±꽵ά��
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			int value1 = *(*(arr + i) + j);	//��׼��ʽ
			int value2 = *(arr[i] + j);	//��ά��ʽ
			//int value3 = arr[i][j];
			printf_s("��ַ��%x\nֵ��%d\n", arr + i + j, value1);
		}
	}

	//5.ָ�뽵ά
	for (parr = arr; parr < arr[0] + 12; parr++)
	{
		printf_s("��ַ��%x\nֵ��%d\n", parr, *parr);
	}
	#pragma endregion

	#pragma region ��ά����ָ�루��ָ�룩
	int scores[][4] = { 70, 77, 80, 85, 58, 64, 79, 80, 88, 72, 92, 96 }, (*prow)[4], *pcol;
	//1.����ܷ���ƽ����
	for (prow = scores; prow < scores + 3; prow++)
	{
		int total = (*prow)[0] + (*prow)[1] + (*prow)[2] + (*prow)[3];
		printf("�ܷ֣�%d��ƽ���֣�%d\n", total, total / 4);
	}

	//2.�ҳ�ÿ�е����ֵ�������
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