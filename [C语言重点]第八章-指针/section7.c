#include <stdio.h>

//定义结构类型
typedef struct student
{
	int stuId;
	char *name;
	char sex;
	float score;
} s;

//示例3
int avg(s *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		float sc = 0;
		sc += ps->score;
		if (sc < 60)
			count++;
	}
	return count;
}

int main777()
{
	#pragma region 结构指针
	//示例：定义学生结构体与结构指针变量
	struct student stu = { 1001, "张三", 'M', 82.5 }, *pstu = &stu;
	//访问成员属性
	printf_s("学号：%d,名称：%s,性别：%s,成绩:%f\n", stu.stuId, stu.name, stu.sex == 'M' ? "男" : "女", stu.score);
	printf_s("学号：%d,名称：%s,性别：%s,成绩:%f\n", (*pstu).stuId, (*pstu).name, (*pstu).sex == 'M' ? "男" : "女", (*pstu).score);
	printf_s("学号：%d,名称：%s,性别：%s,成绩:%f\n", pstu->stuId, pstu->name, pstu->sex == 'M' ? "男" : "女", pstu->score);
	#pragma endregion
	puts("");
	#pragma region 结构数组指针
	struct student stuArr[] = {
		{ 1001, "张三", 'M', 52.5 },
		{ 1002, "李四", 'F', 83.5 },
		{ 1003, "王五", 'M', 64.5 },
		{ 1004, "赵六", 'F', 45.5 },
		{ 1005, "田七", 'M', 86.5 }
	}, *parr_stu;
	for (parr_stu = stuArr; parr_stu < stuArr + 5; parr_stu++)
	{
		printf_s("学号：%d,名称：%s,性别：%s,成绩:%f\n", parr_stu->stuId, parr_stu->name, parr_stu->sex == 'M' ? "男" : "女", parr_stu->score);
	}
	#pragma endregion
	puts("");
	#pragma region 结构指针作为函数参数
	//示例：计算一组学生的平均成绩和不及格人数。用结构指针变量作函数参数。
	parr_stu = stuArr;
	printf_s("不及格人数:%d\n", avg(parr_stu, 5));
	#pragma endregion

	system("pause");
	return 0;
}