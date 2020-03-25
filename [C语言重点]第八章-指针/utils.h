/*********************** 
ͷ�ļ���utils.h 
˵�����Զ������������
***********************/

#pragma region ����ڵ㣨�ṹ�壩
//����(ͷ�ڵ�)
typedef struct list_header
{
	int size;
	struct list_node *first;
} list;

//�ڵ�
typedef struct list_node
{
	int key;   //������,����������
	char *message;
	struct list_node *next; //ָ����
} node;
#pragma endregion

#pragma region ����ԭ��
//��������
//@return:void
list *createLinks();

//�����ڵ�
//@param:key�ڵ��
//@param:message�ڵ�ֵ
//@return:node *
node *createNode(int, char *);

//��ȡ������
//@param:pHead����ͷָ��
//@return:int
int getLength(node *);

//׷�ӽڵ�
//param:node*����ͷָ��
//param:node*׷�ӽڵ�ָ��
//reutrn:void
void addNode(list *, int, char *);

//����ڵ�
//@param:����ͷָ��
//@param:�����Ľڵ�ָ��
//@return:char*
node *insertNode(node *, node *);

//���ҽڵ�
//@param:����ͷָ��
//@param:����ҵĽڵ�λ��
//@return:pointer
node *findNode(node *, int);

//ɾ���ڵ�
//@param:����ͷָ��
//@param:�����Ľڵ�ָ��
//@return:*message
int removeNode(node *, int);

//���½ڵ�
//@param:����ͷָ��
//@param:key�ڵ���
//@param:������Ϣ
//@return:*message
int updateNode(node *, int, int, char *);

//��ӡ����ڵ�
//@param:pHead����ͷָ��
//@return void
void displayNodes(node *);

//����ά��
//@param:pHead����ͷָ��
//@param:start��ʼkey
//@param:step����
//@return void
void checkPrimaries(node *);
#pragma endregion


