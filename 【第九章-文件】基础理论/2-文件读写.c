#include<stdio.h>
#include<stdlib.h>
#define N 3 //�ַ�������
#define MAX_SIZE 30 //�ַ������С��Ҫ��ÿ���ַ������Ȳ�����29

int main()
{
	#pragma region �ַ���д
	char file_name[20] = "D:/data��file.txt";
	FILE * fp = fopen(file_name, "w"); //���ļ�
	int c; //c:����fgetc�ķ���ֵ������Ϊint������char M
	if (NULL == fp)
	{
		printf("Failed tO open the file !\n");
		exit(0);
	}
	printf("�������ַ������س���������");
	while ((c = fgetc(stdin)) != '\n') //stdin:ָ���׼�����豸�����ļ�
	{
		fputc(c, stdout); //stdout:ָ���׼����豸��ʾ���ļ�
		fputc(c, fp);
	}
	fputc('\n', stdout);
	fclose(fp); //�ر��ļ�
	#pragma endregion
	
	#pragma region �ַ�����д
	char file_name[30] = "D:\\file.txt",
		str[MAX_SIZE];
	FILE *fp = fopen(file_name, "w+"); //"w+"ģʽ����д������
	if (fp == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	printf_s("������%d���ַ�����\n", N);
	for (int i = 0; i < N; i++)
	{
		printf_s("�ַ���%d:", i + 1);
		fgets(str, MAX_SIZE, stdin);	//�Ӽ��������ַ���������str������
		fputs(str, fp);		//��str���ַ��������fp��ָ�ļ���
	}
	rewind(fp);		//��fp��ָ�ļ��Ķ�дλ�õ���Ϊ�ļ���ʼ��
	while (fgets(str, MAX_SIZE, fp) != NULL)
	{
		fputs(str, stdout);		//���ַ����������Ļ
	}
	fclose(fp);
	#pragma endregion

	system("pause");
	return 0;
}