
#pragma region 定义节点
//学生结构体
typedef struct student
{
	int stuId;
	char *stuName;
	int gender;
	int age;
	struct student *before;
	struct student *next;
} student;

//班级结构体
typedef struct classes
{
	int clsId;
	char *clsName;
	int total;
	struct student *header;
} classes;
#pragma endregion

#pragma region 双链表函数原型
//添加学生节点
//@param cls 链表头指针
//@param info 新节点指针
//return void
void addTo(classes *cls, student *info);

//插入学生节点
//@param cls 链表头指针
//@param index 插入位置
//@param info 新节点指针
//return int
int insertTo(classes *cls, int index, student *info);

//删除节点
//@param cls 链表头指针
//@param stuId 学生ID
//return void
int deleteAt(classes *cls, int stuId);

//更新节点
//@param cls 链表头指针
//@param info 节点指针
//return int
int updateTo(classes *cls, student *info);

//打印链表
//@param cls 链表头指针
//return void
void showList(classes *cls);

//查询节点
//@param cls 链表头指针
//@param index 查询位置
//@param stuId 学生ID
//return sutdent
student *getStudent(classes *cls, int index, int stuId);

//链表初始化
//return classes
classes *initClasses();

//创建学生节点
//@param stuId
//@param stuName
//@param gender
//@param age
//return student
student *createStudent(int stuId, char *stuName, int gender, int age);
#pragma endregion



