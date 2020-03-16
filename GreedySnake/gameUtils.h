/*******************************
 * gameUtils.h
 * 游戏工具库头文件
********************************/
#pragma region 结构体
//方向枚举
typedef enum direction
{
	up = 119 | 72,
	left = 97 | 75,
	right = 100 | 77,
	down = 115 | 80
} direction;

//结构体-蛇
typedef struct snake
{
	direction dire;
	int X, Y;
	struct snake *next;
} snake;

//结构体-食物
typedef struct food
{
	int score, X, Y;
} food;
#pragma endregion

#pragma region 函数原型

#pragma endregion
