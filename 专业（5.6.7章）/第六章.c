#include <stdio.h>
//����ԭ��
//int getMax(int, int);
//ȫ�ֶ�̬����
int x = 12;
//ȫ�־�̬����
static int all;

//�������
void main()
{
	int arg1 = 4, arg2 = 7;
	int res = getMax(arg1, arg2); //����ʱ����ʵ�ʲ���
	printf_s("%d\n", res);
	printf_s("%d\n", res);
	all + 10;
	system("pause");
}

//�ҳ������
int getMax(int arg1, int arg2)	//ֻ����ʽ����
{
	return arg1 > arg2 ? arg1 : arg2;
}

void getNull()
{
	//do some thing
}