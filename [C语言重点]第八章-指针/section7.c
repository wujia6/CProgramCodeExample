#include <stdio.h>

typedef struct studentInfo
{
	int stuId;
	char *name;
	char gender;
	float score;
} student;

void avg(student *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		 if (ps->score < 60)
			 count++;
	}
	printf_s("不及格人数：%d\n", count);
}

int main777()
{
	#pragma region 结构指针
	//定义结构指针变量
	student stu = { 1001,"张三",'M',62.5 },
		*ps = &stu;
	printf_s("学号：%d,名称：%s,性别：%s,分数：%f\n", stu.stuId, stu.name, stu.gender == 'M' ? "男" : "女", stu.score);
	printf_s("学号：%d,名称：%s,性别：%s,分数：%f\n", (*ps).stuId, (*ps).name, (*ps).gender == 'M' ? "男" : "女", (*ps).score);
	printf_s("学号：%d,名称：%s,性别：%s,分数：%f\n", ps->stuId, ps->name, ps->gender == 'M' ? "男" : "女", ps->score);
	#pragma endregion

	puts("");

	#pragma region 结构数组指针
	student stuArr[]=
	{
		{ 1001,"张三",'M',82.5 },
		{ 1002,"李四",'F',72.5 },
		{ 1003,"王五",'M',82.5 },
		{ 1004,"赵六",'F',92.5 },
		{ 1005,"田七",'M',62.5 }
	}, *pstu = stuArr;
	for (pstu = stuArr; pstu < stuArr + 5; pstu++)
	{
		printf_s("学号：%d,名称：%s,性别：%s,分数：%f\n", pstu->stuId, pstu->name, pstu->gender == 'M' ? "男" : "女", pstu->score);
	}
	#pragma endregion

	puts("");

	#pragma region 结构指针作为函数参数
	//计算一组学生的平均成绩和不及格人数。用结构指针变量作函数参数。
	avg(pstu, 5);
	#pragma endregion

	system("pause");
	return 0;
}