#include <stdio.h>

//定义结构
typedef struct student
{
	int stuId;
	char *name;
	char sex;
	float score;
} s;

//示例：计算一组学生的平均成绩和不及格人数
int avg(s *ps, int len)
{
	int count = 0;
	for (int i = 0; i < len; i++, ps++)
	{
		//求平均成绩
		float sc = 0;
		sc += ps->score;
		if (sc / 5 < 60)
			count++;
	}
	return count;
}

int main()
{
	#pragma region 结构指针
	//定义结构变量与指针变量
	s stu = { 1001,"张三",0,82.5 }, *pstu = &stu;
	//访问成员变量
	printf_s("学号：%d,姓名：%s,性别：%s,分数：%f\n", stu.stuId, stu.name, stu.sex == 'F' ? "女" : "男", stu.score);
	printf_s("学号：%d,姓名：%s,性别：%s,分数：%f\n", (*pstu).stuId, (*pstu).name, (*pstu).sex == 'F' ? "女" : "男", (*pstu).score);
	printf_s("学号：%d,姓名：%s,性别：%s,分数：%f\n", pstu->stuId, pstu->name, pstu->sex == 'F' ? "女" : "男", pstu->score);
	#pragma endregion

	puts("");

	#pragma region 结构数组指针
	s stuArr[] = 
	{
		{101,"Zhou ping",'M',45},
		{102,"Zhang ping",'M',62.5},
		{103,"Liou fang",'F',92.5},
		{104,"Cheng ling",'F',87},
		{105,"Wang ming",'M',58}
	}, *p_stu;
	for (p_stu = stuArr; p_stu < stuArr + 5; p_stu++)
	{
		printf_s("学号：%d,姓名：%s,性别：%s,分数：%f\n", p_stu->stuId, p_stu->name, p_stu->sex == 'F' ? "女" : "男", p_stu->score);
	}
	#pragma endregion

	puts("");

	#pragma region 结构指针作为函数参数
	p_stu = stuArr;
	printf_s("不及格人数:%d\n", avg(p_stu, 5));
	#pragma endregion
	system("pause");
	return 0;
}

