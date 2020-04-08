#include <stdio.h>
#define PI 3.14
#define P printf_s
#define	D "%d\n"
#define C "%c\n"
#define F "%f\n"

void main()
{
	//1.常量（普通常量，符号常量）
	/*const int ID = 10;
	const float PRICE = 12.5;
	const char CH = 'A';

	int id = 10;
	float price = 12.5;
	char ch = 'a';

	int sum = PI + 15;
	int res = 10 % 3;*/


	/*int num = 10;*/
	//num++;//后自增 先计算，后自增
	//int sum = num;
	//++num;//前自增 先自增，后计算
	/*P(D, ++num);*/


	//0=false(假)
	//1=true(真)

	/*P(D, !num);
	P(C, CH);
	P(F, price);*/

	/*int sum = 2;
	if (sum == 0)
	{
		sum++;
	}
	else if(sum==1)
	{
		sum--;
	}
	else
	{
		sum += 10;
	}
	P(D, sum);*/

	//堆栈
	int a[5], m = 10, k = 8;
	for (int i = 0; m > 0;)
	{
		a[i] = m % k;
		printf_s("i=%d\tm=%0x=%d\tk=%0x=%d\ta[i]=%0x=%d\n", i, &m,m, &k,k, &a[i],a[i]);
		i++;
	}

	system("pause");
}