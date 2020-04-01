
#pragma region ����ڵ�
//ѧ���ṹ��
typedef struct student
{
	int stuId;
	char *stuName;
	int gender;
	int age;
	struct student *before;
	struct student *next;
} student;

//�༶�ṹ��
typedef struct classes
{
	int clsId;
	char *clsName;
	int total;
	struct student *header;
} classes;
#pragma endregion

#pragma region ˫������ԭ��
//���ѧ���ڵ�
//@param cls ����ͷָ��
//@param info �½ڵ�ָ��
//return void
void addTo(classes *cls, student *info);

//����ѧ���ڵ�
//@param cls ����ͷָ��
//@param index ����λ��
//@param info �½ڵ�ָ��
//return int
int insertTo(classes *cls, int index, student *info);

//ɾ���ڵ�
//@param cls ����ͷָ��
//@param stuId ѧ��ID
//return void
int deleteAt(classes *cls, int stuId);

//���½ڵ�
//@param cls ����ͷָ��
//@param info �ڵ�ָ��
//return int
int updateTo(classes *cls, student *info);

//��ӡ����
//@param cls ����ͷָ��
//return void
void showList(classes *cls);

//��ѯ�ڵ�
//@param cls ����ͷָ��
//@param index ��ѯλ��
//@param stuId ѧ��ID
//return sutdent
student *getStudent(classes *cls, int index, int stuId);

//�����ʼ��
//return classes
classes *initClasses();

//����ѧ���ڵ�
//@param stuId
//@param stuName
//@param gender
//@param age
//return student
student *createStudent(int stuId, char *stuName, int gender, int age);
#pragma endregion



