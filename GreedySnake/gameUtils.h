/*******************************
 * gameUtils.h
 * 游戏工具库头文件
********************************/

#pragma region 符号常量
#define ROW 30	//定义地图行列（二维数组）
#define COLUMN 60
#define DEF_LEN 4	//蛇身初始长度
#define WAIT_SECOND 500	//蛇移动速度
#pragma endregion

#pragma region 结构体
//方向枚举
typedef enum Direction
{
	up = 119 | 72,
	left = 97 | 75,
	right = 100 | 77,
	down = 115 | 80
} direction;

//结构体-蛇
typedef struct Snake
{
	direction dire;
	int x, y;
	struct Snake *perv;
	struct Snake *next;
} snake;

//结构体-食物
typedef struct Food
{
	int score, X, Y;
} foods;
#pragma endregion

#pragma region 全局变量
char Map[ROW][COLUMN] = { 0 };
snake *p_snake;					//蛇(头指针)
snake *p_snake_last;            //蛇尾(追后一个节点)
foods food;						//食物
#pragma endregion

#pragma region 函数原型
//初始化
void initMap(char *);
void initSnake();
void createFood();
void Move();
#pragma endregion
