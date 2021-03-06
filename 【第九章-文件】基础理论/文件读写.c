#include<stdio.h>
#include<stdlib.h>
#define N 3 //字符串个数
#define MAX_SIZE 30 //字符数组大小，要求每个字符串长度不超过29

int main11()
{
	#pragma region 字符读写
	char file_name1[20] = "d:/data—file.txt";
	FILE *fp1 = fopen(file_name1, "w"); //打开文件
	int c; //c:接收fgetc的返回值，定义为int，而非char M
	if (fp1 == NULL)
	{
		printf("Failed tO open the file !\n");
		exit(0);
	}
	printf("请输入字符，按回车键结束：");
	while ((c = fgetc(stdin)) != '\n') //stdin:指向标准输人设备键盘文件
	{
		fputc(c, stdout); //stdout:指向标准输出设备显示器文件
		fputc(c, fp1);
	}
	fputc('\n', stdout);
	fclose(fp1); //关闭文件
	#pragma endregion
	
	#pragma region 字符串读写
	char file_name2[30] = "d:\\file.txt",
		str[MAX_SIZE];
	FILE *fp2 = fopen(file_name2, "w+"); //"w+"模式：先写入后读出
	if (fp2 == NULL)
	{
		printf("文件打开失败!\n");
		exit(0);
	}
	printf_s("请输入%d个字符串：\n", N);
	for (int i = 0; i < N; i++)
	{
		printf_s("字符串%d:", i + 1);
		fgets(str, MAX_SIZE, stdin);	//从键盘输入字符串，存入str数组中
		fputs(str, fp2);		//把str中字符串输出到fp所指文件中
	}
	rewind(fp2);		//把fp所指文件的读写位置调整为文件开始处
	while (fgets(str, MAX_SIZE, fp2) != NULL)
	{
		fputs(str, stdout);		//把字符串输出到屏幕
	}
	fclose(fp2);
	#pragma endregion

	system("pause");
	return 0;
}