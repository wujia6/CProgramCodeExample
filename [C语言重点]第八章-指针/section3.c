#include <stdio.h>
#include <malloc.h>
#include <string.h>

char *func_copy(char *dest, char *src)
{
	char *tmp = dest;
	while (*tmp++ = *src++);
	return dest;
}

void func_strcopy(char *dest, char *src)
{
	char *tmp = dest;
	while (*tmp++ = *src++);
}

void main333()
{
	char *src = "Hunan ShaoYang Hongxiang School",
		*dest = (char*)malloc(sizeof(char) * 50);
	puts(func_copy(dest, src));

	system("pause");
}

