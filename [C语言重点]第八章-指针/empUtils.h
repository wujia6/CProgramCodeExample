#pragma region 定义节点
//员工结构体
typedef struct _employee
{
	int empId;
	char *empName;
	int gender;
	int age;
	struct _employee *next;
} employee;

//部门结构体
typedef struct _depart
{
	int depId;
	char *depName;
	int peoples;
	struct _employee *first;
} depart;

#pragma endregion

#pragma region 函数原型

depart *initialize(int, char *);

employee *createEntry(int key, char *name, int gender, int age);

void displayAll(depart *);

employee *searchBy(depart *dep, char *filter, int empId);

void appendTo(depart *dep, employee *entry);

int insertAt(int index, employee *entry);

int removeBy(depart *dep, int empId);

int editTo(depart *dep, employee *emp);

#pragma endregion
