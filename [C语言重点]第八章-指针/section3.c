#include <stdio.h>
#include <string.h>

//ʾ��1
int findCH(char *pstr)
{
	for (int i = 0; i < strlen(pstr); i++)
	{
		if (pstr[i] == 'k')
			return 1;
	}
	return 0;
}

//ʾ��2
void formatter()
{
	char *pd = "%d\n", *pc = "%c\n", *ps = "%s\n", *px = "%x\n";
	printf_s(pd, 10);
	printf_s(pc, 'g');
	printf_s(ps, "Hello World");
	//printf_s(px, 10799772);
}

//ʾ��3
void strCopy(char *pstr1, char *pstr2)
{
	while (*pstr2++ = *pstr1++);
}

void maindddd()
{
	//1.�ַ���ָ�붨��
	char str[] = "HongXiang School";
	char *string1 = "C Program Diesgn", *string2="";

	for (int i = 0; i < strlen(str); i++)
	{
		printf_s("%c", string1[i]);
	}
	puts("");
	//puts(string);

	//2.�޸��ַ���ָ��
	//str[4] = 'k';
	//puts(str);

	//�ַ���ָ�����ʾ��
	//��VS����ʾ������������ַ����в������ޡ�k���ַ���
	//��VS����ʾ������ָ�����ָ��һ����ʽ�ַ�������printf������ʹ�ø�ʽ�ַ�����
	//��VS����ʾ����Ҫ���һ���ַ��������ݸ��Ƶ���һ���ַ����У��ַ���ָ����Ϊ��������ʹ��(����ʹ��sring.h������)��*/
	//����ʾ��1
	if (findCH(string1))
		puts("�����ַ�'k'");
	else
		puts("�������ַ�'k'");

	//����ʾ��2
	formatter();

	//����ʾ��3
	strCopy(string1, string2);
	puts(string2);
	system("pause");
}

