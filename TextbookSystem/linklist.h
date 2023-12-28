#ifndef __LINKLIST_H__
#define __LINKLIST_H__
typedef struct Node1
{
	char name[20];     //教材名称
	char publisher[100];//出版社
	char author[10];   //作者
	int year;          //出版时间
	char buy_name[20]; //订购人
	int buy_num;       //订购数量
    int arrival_num;   //到货数量
	char issue_name[20];//发放人
	int issue_num;     //发放数量
}Node1;                //教材信息

typedef Node1 datatype;
typedef struct Node
{
	union {
		datatype data;
		int len;
	};
	struct Node* next;
}Linklist;             //链表


//创建
Linklist* list_create();
//判空
int list_empty(Linklist* L);
//遍历
int list_show(Linklist* L);
//结点函数
Linklist* node_buy(datatype e);
//尾插
int list_insert_tail(Linklist* L, datatype e);
//尾删
int list_delete_tail(Linklist* L);
//按值查找
int list_search_value(Linklist* L, datatype e);
//按值修改
int list_update_value(Linklist* L, datatype e);
//销毁链表
void list_free(Linklist* L);
//按值删除
int list_delete_value(Linklist* L, datatype e);

//菜单
void menu(Linklist* L, int n);
//1.添加教材
int Textbook_input(Linklist* L);
//2.删除教材
int Textbook_delete(Linklist* L);
//3.修改教材
int Textbook_update(Linklist* L);
//4.查询教材
int Textbook_search(Linklist* L);
//5.教材订购管理
int Textbook_buy(Linklist* L);
//6.教材到货管理
int Textbook_arrival(Linklist* L);
//7.教材发放管理
int Textbook_issue(Linklist* L);
//8.按出版社统计教材
int Textbook_count(Linklist* L);
//9.按出版时间统计教材
int Textbook_count_year(Linklist* L);
//10，输出所有教材信息
int Textbook_show(Linklist* L);
//11.将链表中的教材信息写入文件
int Textbook_write(Linklist* L);


#endif	
