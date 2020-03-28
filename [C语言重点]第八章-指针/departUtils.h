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

depart *initDepart(int depId, char *depName);

employee *createEntrys(int empId, char *empName, int gender, int age);

void displayAlls(depart *dep);

//employee *searchBy(depart *dep, char *filter, int empId);

void appendAt(depart *dep, employee *entry);

//int insertAt(int index, employee *entry);
//
//int removeBy(depart *dep, int empId);
//
//int editTo(depart *dep, employee *emp);

#pragma endregion