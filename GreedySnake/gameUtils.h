/*******************************
 * gameUtils.h
 * ��Ϸ���߿�ͷ�ļ�
********************************/

#pragma region ���ų���
#define ROW 30	//�����ͼ���У���ά���飩
#define COLUMN 60
#define DEF_LEN 4	//�����ʼ����
#define WAIT_SECOND 500	//���ƶ��ٶ�
#pragma endregion

#pragma region �ṹ��
//����ö��
typedef enum Direction
{
	up = 119 | 72,
	left = 97 | 75,
	right = 100 | 77,
	down = 115 | 80
} direction;

//�ṹ��-��
typedef struct Snake
{
	direction dire;
	int x, y;
	struct Snake *perv;
	struct Snake *next;
} snake;

//�ṹ��-ʳ��
typedef struct Food
{
	int score, X, Y;
} foods;
#pragma endregion

#pragma region ȫ�ֱ���
char Map[ROW][COLUMN] = { 0 };
snake *p_snake;					//��(ͷָ��)
snake *p_snake_last;            //��β(׷��һ���ڵ�)
foods food;						//ʳ��
#pragma endregion

#pragma region ����ԭ��
//��ʼ��
void initMap(char *);
void initSnake();
void createFood();
void Move();
#pragma endregion
