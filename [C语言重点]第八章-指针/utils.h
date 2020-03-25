/*********************** 
头文件：utils.h 
说明：自定义链表操作库
***********************/

#pragma region 定义节点（结构体）
//链表(头节点)
typedef struct list_header
{
	int size;
	struct list_node *first;
} list;

//节点
typedef struct list_node
{
	int key;   //数据域,索引、主键
	char *message;
	struct list_node *next; //指针域
} node;
#pragma endregion

#pragma region 函数原型
//创建链表
//@return:void
list *createLinks();

//创建节点
//@param:key节点键
//@param:message节点值
//@return:node *
node *createNode(int, char *);

//获取链表长度
//@param:pHead链表头指针
//@return:int
int getLength(node *);

//追加节点
//param:node*链表头指针
//param:node*追加节点指针
//reutrn:void
void addNode(list *, int, char *);

//插入节点
//@param:链表头指针
//@param:需插入的节点指针
//@return:char*
node *insertNode(node *, node *);

//查找节点
//@param:链表头指针
//@param:需查找的节点位置
//@return:pointer
node *findNode(node *, int);

//删除节点
//@param:链表头指针
//@param:需插入的节点指针
//@return:*message
int removeNode(node *, int);

//更新节点
//@param:链表头指针
//@param:key节点编号
//@param:更新消息
//@return:*message
int updateNode(node *, int, int, char *);

//打印链表节点
//@param:pHead链表头指针
//@return void
void displayNodes(node *);

//主键维护
//@param:pHead链表头指针
//@param:start起始key
//@param:step步长
//@return void
void checkPrimaries(node *);
#pragma endregion


