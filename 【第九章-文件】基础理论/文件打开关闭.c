#include <stdio.h>

int main()
{
	#pragma region �ļ��򿪹ر�
	//'fopen': This function or variable may be unsafe.Consider using fopen_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.
	FILE *fp1, *fp2;
	if ((fp1 = fopen("d:/demo/example1.txt", "r")) != NULL)
	{
		puts("���ļ��������ӣ�ֻ��ģʽ�򿪳ɹ�");
		exit(0);
	}
	if ((fp2 = fopen("d/demo/example2.txt", "a")) != NULL)
	{
		puts("���ļ��������ӣ�׷��ģʽ�򿪳ɹ�");
		exit(0);
	}
	fclose(fp1);
	fclose(fp2);
	#pragma endregion

	system("pause");
	return 0;
}