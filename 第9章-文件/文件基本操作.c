#include <stdio.h>
#include <stdlib.h>

int main()
{
	#pragma region �ļ��򿪹ر�
	//������	����	˵��	��Ŀ	�ļ�	��	��ֹ��ʾ״̬
	//'fopen': This function or variable may be unsafe.Consider using fopen_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details

	errno_t err;
	FILE *stream1, *stream2;
	if ((stream1 = fopen("d:/demo/example1.txt", "r")) != 0)
	{
		puts("���ļ��������ӣ�ֻ��ģʽ�򿪳ɹ�");
		//exit(0);
	}
	if ((stream2 = fopen("d/demo/example2.txt", "a")) != 0)
	{
		puts("���ļ��������ӣ�׷��ģʽ�򿪳ɹ�");
		//exit(0);
	}
	fclose(stream1);
	fclose(stream2);
	#pragma endregion

	system("pause");
	return 0;
}