#pragma once

#pragma region ����ṹ
typedef struct StudentInfo
{
	int stuId;
	char *stuName;
	char stuGender;
	float stuScore;
	struct StudentInfo *next;
} student;

typedef struct Node
{
	//������
	int index;
	char *message;
	//ָ����
	struct Node *next;
} node;
#pragma endregion

#pragma region ����ԭ��
node *createNode(int, char *);

void appendNode(node *, node *);

void insertNode(node *, int, node *);

node *findNode(node *, int);

int removeNode(node *, int);

void updateNode(node *, int, char*);
#pragma endregion
