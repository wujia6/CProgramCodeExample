#include <stdio.h>
#define P printf_s
#define D "%d\n"
#define C "%c\n"
#define F "%f\n"

void main()
{
	//常量
	//1.整型常量 2.字符型常量 3.浮点型常量 4.符号常量
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

	//数据输入输出
	//1.putchar() printf() 2.getchar() scanf()
	putchar('A');
	P(D, 20);

	char input = getchar();
	P(C, input);
	scanf("%d %c %f",)

	system("pause");
}