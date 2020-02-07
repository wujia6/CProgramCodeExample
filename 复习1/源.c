#include <stdio.h>
#define LEN 100

void main()
{
	//将自然数1~100按顺时针围成一圈，首先取出1，然后按顺时针方向以步长30取数，(已取出的数不再参加计数)，
	//直至所有的数取完为止。编程求最后一个取出的数是多少？(共15分)【2009年选做题】
	int a[LEN], m = 30;

	for (int j = 0; j < LEN; j++)
	{
		a[j] = j + 1;
		int k = 1;
		int i = -1;
		while (1)
		{
			for (int j = 0; j < m;)
			{
				i = (i + 1) % LEN;
				if (a[i] != 0)
					j++;
			}
			if (k == LEN)
				break;
			a[i] = 0;
			k++;
		}
	}
}