#include <stdio.h>
#define PI 3.14
#define P printf_s
#define	D "%d\n"
#define C "%c\n"
#define F "%f\n"

void main()
{
	//1.��������ͨ���������ų�����
	/*const int ID = 10;
	const float PRICE = 12.5;
	const char CH = 'A';

	int id = 10;
	float price = 12.5;
	char ch = 'a';

	int sum = PI + 15;
	int res = 10 % 3;*/


	/*int num = 10;*/
	//num++;//������ �ȼ��㣬������
	//int sum = num;
	//++num;//ǰ���� �������������
	/*P(D, ++num);*/


	//0=false(��)
	//1=true(��)

	/*P(D, !num);
	P(C, CH);
	P(F, price);*/

	int sum = 2;
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
	P(D, sum);

	system("pause");
}