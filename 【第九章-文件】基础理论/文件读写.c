#include<stdio.h>
#include<stdlib.h>
#define N 3 //�ַ�������
#define MAX_SIZE 30 //�ַ������С��Ҫ��ÿ���ַ������Ȳ�����29

int main11()
{
	#pragma region �ַ���д
	char file_name1[20] = "d:/data��file.txt";
	FILE *fp1 = fopen(file_name1, "w"); //���ļ�
	int c; //c:����fgetc�ķ���ֵ������Ϊint������char M
	if (fp1 == NULL)
	{
		printf("Failed tO open the file !\n");
		exit(0);
	}
	printf("�������ַ������س���������");
	while ((c = fgetc(stdin)) != '\n') //stdin:ָ���׼�����豸�����ļ�
	{
		fputc(c, stdout); //stdout:ָ���׼����豸��ʾ���ļ�
		fputc(c, fp1);
	}
	fputc('\n', stdout);
	fclose(fp1); //�ر��ļ�
	#pragma endregion
	
	#pragma region �ַ�����д
	char file_name2[30] = "d:\\file.txt",
		str[MAX_SIZE];
	FILE *fp2 = fopen(file_name2, "w+"); //"w+"ģʽ����д������
	if (fp2 == NULL)
	{
		printf("�ļ���ʧ��!\n");
		exit(0);
	}
	printf_s("������%d���ַ�����\n", N);
	for (int i = 0; i < N; i++)
	{
		printf_s("�ַ���%d:", i + 1);
		fgets(str, MAX_SIZE, stdin);	//�Ӽ��������ַ���������str������
		fputs(str, fp2);		//��str���ַ��������fp��ָ�ļ���
	}
	rewind(fp2);		//��fp��ָ�ļ��Ķ�дλ�õ���Ϊ�ļ���ʼ��
	while (fgets(str, MAX_SIZE, fp2) != NULL)
	{
		fputs(str, stdout);		//���ַ����������Ļ
	}
	fclose(fp2);
	#pragma endregion

	system("pause");
	return 0;
}