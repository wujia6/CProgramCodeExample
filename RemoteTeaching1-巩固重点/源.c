#include <stdio.h>
#define P printf_s
#define D "%d\n"
#define C "%c\n"
#define F "%f\n"

void main()
{
	//����
	//1.���ͳ��� 2.�ַ��ͳ��� 3.�����ͳ��� 4.���ų���
	const int NUM = 10;
	const char CH = 'A';
	const float PRICE = 3.14;
	P(D, NUM);
	P(C, CH);
	P(F, PRICE);
	puts("");
	int num = 3;
	char ch = 'a';
	float price = 12.5;
	num += price;
	ch += 1;
	price += num;
	P(D, num);
	P(C, ch);
	P(F, price);

	//�����������
	//1.putchar() printf() 2.getchar() scanf()
	putchar('A');
	P(D, 20);

	char input = getchar();
	P(C, input);

	system("pause");
}