#pragma once

#pragma region 定义结构
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
	//数据域
	int index;
	char *message;
	//指针域
	struct Node *next;
} node;
#pragma endregion

#pragma region 函数原型
node *createNode(int, char *);

void appendNode(node *, node *);

void insertNode(node *, int, node *);

node *findNode(node *, int);

int removeNode(node *, int);

void updateNode(node *, int, char*);
#pragma endregion
