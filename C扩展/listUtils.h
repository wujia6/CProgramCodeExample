#pragma region ����ڵ�
//Ա���ṹ��
typedef struct _employee
{
	int empId;
	char *empName;
	int gender;
	int age;
	struct _employee *next;
} employee;

//���Žṹ��
typedef struct _depart
{
	int depId;
	char *depName;
	int peoples;
	struct _employee *first;
} depart;

typedef struct student
{
	int stuId;
	char *stuName;
	int gender;
	int age;
	struct student *before;
	struct student *next;
} student;

typedef struct classes
{
	int clsId;
	char *clsName;
	int total;
	struct student *header;
} classes;

#pragma endregion

#pragma region ��������ԭ��
depart *initDepart(int depId, char *depName);

employee *createEntrys(int empId, char *empName, int gender, int age);

void displayAlls(depart *dep);

employee *searchBy(depart *dep, int empId);

void appendAt(depart *dep, employee *entry);

int insertAt(depart *dep, int index, employee *entry);

int removeBy(depart *dep, int empId);

int editTo(depart *dep, employee *entry);
#pragma endregion

#pragma region ˫������ԭ��
void addTo(classes *cls, student *info);

int insertTo(classes *cls, int index, student *info);

int deleteAt(classes *cls, int stuId);

int updateTo(classes *cls, student *info);

void showlist(classes *cls);

student *getStudent(classes *cls, int index, int stuId);

classes *initClass();

student *initStudent(int stuId, char *stuName, int gender, int age);
#pragma endregion



