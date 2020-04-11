#include <stdio.h>
#include <stdlib.h>

int main()
{
	#pragma region 文件打开关闭
	//严重性	代码	说明	项目	文件	行	禁止显示状态
	//'fopen': This function or variable may be unsafe.Consider using fopen_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details

	errno_t err;
	FILE *stream1, *stream2;
	if ((stream1 = fopen("d:/demo/example1.txt", "r")) != 0)
	{
		puts("与文件建立连接，只读模式打开成功");
		//exit(0);
	}
	if ((stream2 = fopen("d/demo/example2.txt", "a")) != 0)
	{
		puts("与文件建立连接，追加模式打开成功");
		//exit(0);
	}
	fclose(stream1);
	fclose(stream2);
	#pragma endregion

	system("pause");
	return 0;
}