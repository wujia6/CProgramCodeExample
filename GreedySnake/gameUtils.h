/*******************************
 * gameUtils.h
 * ��Ϸ���߿�ͷ�ļ�
********************************/
#pragma region �ṹ��
//����ö��
typedef enum direction
{
	up = 119 | 72,
	left = 97 | 75,
	right = 100 | 77,
	down = 115 | 80
} direction;

//�ṹ��-��
typedef struct snake
{
	direction dire;
	int X, Y;
	struct snake *next;
} snake;

//�ṹ��-ʳ��
typedef struct food
{
	int score, X, Y;
} food;
#pragma endregion

#pragma region ����ԭ��

#pragma endregion
