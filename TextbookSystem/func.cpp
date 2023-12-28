#include"linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>


//菜单
void menu(Linklist* L, int n)
{
	while (1)
	{
		printf("-----------------------------------教材管理系统-----------------------------\n");
		printf("----------                         0.退出                        -----------\n");
		printf("----------                         1.添加教材                    ----------\n");
		printf("----------                         2.删除教材                    ----------\n");
		printf("----------                         3.修改教材                    --------- \n");
		printf("----------                         4.查找教材                    ----------\n");
		printf("----------                         5.教材订购管理                ----------\n");
		printf("----------                         6.教材到货管理                -----------\n");
		printf("----------                         7.教材发放管理                -----------\n");
		printf("----------                         8.按出版社统计数量            ------------\n");
		printf("----------                         9.按时间统计数量              -------------\n");
		printf("----------                         10.查看所有教材信息           ------------\n");
		printf(" ---------                         11.输出所有信息到文件中       --------------\n");
		printf(" ----------------------------------请选择功能----------------------------------\n");
		scanf_s("%d", &n);

		switch (n)
		{
		case 0:
			printf("-------------------------退出----------------------\n");
			return;
			break;

		case 1:
			printf("-----------------------添加教材--------------------\n");
			Textbook_input(L);
			break;
		case 2:
			printf("-----------------------删除教材--------------------\n");
			Textbook_delete(L);
			break;
		case 3:
			printf("-----------------------修改教材---------------------\n");
			Textbook_update(L);
			break;
		case 4:
			printf("-----------------------查找教材-----------------------\n");
			Textbook_search(L);
			break;
		case 5:
			printf("--------------------教材订购管理----------------------\n");
			Textbook_buy(L);
			break;
		case 6:
			printf("--------------------教材到货管理---------------------\n");
			Textbook_arrival(L);
			break;
		case 7:
			printf("--------------------教材发放管理---------------------\n");
			Textbook_issue(L);
			break;
		case 8:
			printf("-------------------按出版社统计数量---------------------\n");
			Textbook_count(L);
			break;
		case 9:
			printf("--------------------按时间统计数量------------------------\n");
			Textbook_count_year(L);
			break;
		case 10:
			printf("--------------------输出所有教材信息------------------------\n");
			Textbook_show(L);
			break;
		case 11:
			printf("--------------------输出所有信息到文件中------------------------\n");
			Textbook_write(L);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
	}
}
//1.添加教材
int Textbook_input(Linklist* L)
{
	datatype e;
	printf("请输入需要添加的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name,20);
	printf("请输入教材所属出版社\n");
	scanf_s("%s", &e.publisher,100);
	printf("请输入作者：\n");
	scanf_s("%s", &e.author,10);
	printf("请输入教材出版年份\n");
	scanf_s("%d", &e.year);

	//Linklist* p = node_buy(e);	//创建节点
	list_insert_tail(L, e);    //尾插
	return 0;
}
//2.按值删除教材
int Textbook_delete(Linklist* L)
{
	datatype e;
	printf("请输入需要删除的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name,20);
	list_delete_value(L, e);    //按值删除
	return 0;
}
//3.修改教材
int Textbook_update(Linklist* L)
{
	datatype e;
	printf("请输入需要修改的教材信息：\n");
	printf("请输入教材新名称（或保持不变）\n");
	scanf_s("%s", e.name,20);
	printf("请输入新出版社 （或保持不变）\n");
	scanf_s("%s", &e.publisher,20);
	printf("请输入新出版年份（或保持不变）\n");
	scanf_s("%d", &e.year);
	printf("请输入新作者（或保持不变）\n");
	scanf_s("%s", &e.author,10);
	//printf("请输入订购数量（默认-1）：");
	//scanf_s("%d", &e.buy_num);
	//e.buy_num = -1;
	//printf("请输入到货数量（默认-1）：");
	//scanf_s("%d", &e.arrival_num);
	//e.arrival_num = -1;
	//printf("请输入发放数量（默认-1）：");
	//scanf_s("%d", &e.issue_num);
	//使用一个新节点来存储更改后的信息
	//Linklist* p = node_buy(e);
	list_update_value(L, e);
	return 0;
}
//4.查找教材
int Textbook_search(Linklist* L)
{
	datatype e;
	printf("请输入需要查找的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name,20);
	list_search_value(L, e);
	return 0;
}
//5.教材订购管理
int Textbook_buy(Linklist* L)
{
	datatype e;
	printf("请输入需要订购的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name, 20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;

	}
	printf("请输入订购人：\n");
	scanf_s("%s", &e.buy_name,20);
	strcpy_s(p->data.buy_name, e.buy_name);
	printf("请输入订购数量\n");
	scanf_s("%d", &e.buy_num);
	p->data.buy_num = e.buy_num;
	printf("已经订购%d本教材,订购人是：%s\n", e.buy_num,e.buy_name);
	return 0;
}
//6.教材到货管理
int Textbook_arrival(Linklist* L)
{
	datatype e;
	printf("请输入到货的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name, 20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;
	}
	printf("请输入到货数量\n");
	scanf_s("%d", &e.arrival_num);
	p->data.arrival_num = e.arrival_num;
 	printf("----------------------------已经到货咯%d本教材-------------------\n", e.arrival_num);
	return 0;
}
//7.教材发放管理
int Textbook_issue(Linklist* L)
{
	datatype e;
	printf("请输入需要发放的教材信息：\n");
	printf("请输入教材名称\n");
	scanf_s("%s", e.name,20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;
	}
	printf("请输入发放人：\n");
	scanf_s("%s", &e.issue_name,20);
	strcpy_s(p->data.issue_name, e.issue_name);
	printf("请输入发放数量\n");
	scanf_s("%d", &e.issue_num);
	p->data.issue_num = e.issue_num;
	printf("已经发放%d本教材,发放人是：%s\n",e.issue_num,e.issue_name);
	return 0;
}
//8.按出版社统计教材
int Textbook_count(Linklist* L)
{
	//遍历链表，把出版社相同的教材的订购数量，到货数量以及发放数量分别相加后输出
	
	char pub[20];
	printf("请输入需要按哪家出版社统计数量：\n");
	scanf_s("%s",pub,20);
	int count_buy = 0;
	int count_arrival = 0;
	int count_issue = 0;
	Linklist* p = L;
	while (p != NULL)
	{
		if (strcmp(p->data.publisher,pub) == 0)
		{
			count_buy += p->data.buy_num;
			count_arrival += p->data.arrival_num;
			count_issue += p->data.issue_num;
		}
		p = p->next;
	}
	printf("--------------该出版社订购数量为%d，到货数量为%d，发放数量为%d----------------\n", count_buy, count_arrival, count_issue);
	return 0;
}
//9.按年份统计教材
int Textbook_count_year(Linklist* L)
{
	//遍历链表，把年份相同的教材的订购数量，到货数量以及发放数量输出
	int year;
	printf("请输入需要按哪一年统计数量：\n");
	scanf_s("%d", &year);
	int count_buy = 0;
	int count_arrival = 0;
	int count_issue = 0;
	Linklist* p = L;
	while (p != NULL)
	{
		if (p->data.year == year)
		{
			count_buy += p->data.buy_num;
			count_arrival += p->data.arrival_num;
			count_issue += p->data.issue_num;
		}
		p = p->next;
	}
	printf("该年订购数量为%d，到货数量为%d，发放数量为%d\n", count_buy, count_arrival, count_issue);
	return 0;
}
//10.输出所有教材信息
int Textbook_show(Linklist* L)
{
	list_show(L);
	return 0;
}
//11.将链表中的数据写入文件
int Textbook_write(Linklist* L)
{
	FILE* fp = fopen("Textbook.txt", "w");
	if (NULL == fp)
	{
		printf("文件打开失败\n");
		return -1;
	}
	Linklist* p = L;
	while (p != NULL)
	{
		fprintf(fp, "--------------------------------------------------------------------------------------------------------------------");
		fprintf(fp, "书名：%s 作者：%s 出版社：%s 出版日期：%d \n", p->data.name, p->data.author, p->data.publisher, p->data.year);
		fprintf(fp,"订购人：%s,订购数量：%d，到货数量：%d,发放人：%s,发放数量：%d\n", p->data.buy_name, p->data.buy_num,p->data.arrival_num,p->data.issue_name,p->data.issue_num);
		fprintf(fp,"---------------------------------------------------------------------------------------------------------------------");
		p = p->next;
	}
	fclose(fp);
	return 0;
}


//创建
Linklist* list_create()
{
	Linklist* L = (Linklist*)malloc(sizeof(Linklist));
	if (NULL == L)
	{
		printf("创建失败\n");
		return NULL;
	}

	//初始化
	L->len = 0;
	L->next = NULL;

	printf("创建成功\n");
	return L;
}
//判空
int list_empty(Linklist* L)
{
	if (0 == L->len)
	{
		printf("链表为空\n");
		return 1;
	}
}

//定义申请节点函数
Linklist* node_buy(datatype e)
{
	Linklist* p = (Linklist*)malloc(sizeof(Linklist));
	if (NULL == p)
	{
		printf("节点申请失败\n");
		return NULL;
	}
	strcpy_s(p->data.name, e.name);
	strcpy_s(p->data.publisher, e.publisher);
	strcpy_s(p->data.author, e.author);
	p->data.year = e.year;
	p->data.buy_num = 0;           //订购数量,默认为0
	p->data.arrival_num= 0;        //到货数量,默认为0
	p->data.issue_num = 0;         //发放数量,默认为0
	strcpy_s(p->data.buy_name,"暂无");        //订购人,默认
	strcpy_s(p->data.issue_name,"暂无");     //发放人,默认
	p->next = NULL;

	return p;
}

//尾插法,插入节点
int list_insert_tail(Linklist* L, datatype e)
{
	if (NULL == L)
	{
		return -1;
	}
	Linklist* p = node_buy(e);
	
	Linklist* q = L;
	while (q->next != NULL)
	{
		q = q->next;
	}
	q->next = p;
	L->len++;
	printf("------------------------------------恭喜你，添加成功了哟--------------------------\n");
	return 0;
}


//按教材名称在链表中查询，输出教材信息
int list_search_value(Linklist* L, datatype e)
{
	if (L == NULL)
	{
		return -1;
	}
	Linklist* p = L;
	int i = 1;
	while (p->next != NULL) 
	{
		if (strcmp(p->next->data.name, e.name) == 0)
		{
			printf("-----------------找到了!！以下是教材信息------------------\n");
			printf("教材名称：%s\n", p->next->data.name);
			printf("出版社：%s\n", p->next->data.publisher);
			printf("作者：%s\n", p->next->data.author);
			printf("出版年份：%d\n", p->next->data.year);
			printf("订购数量：%d，订购人：%s\n", p->next->data.buy_num,p->next->data.buy_name);
			printf("到货数量：%d\n", p->next->data.arrival_num);
			printf("发放数量：%d,发放人：%s\n", p->next->data.issue_num,p->next->data.issue_name);
			printf("----------------------------------------------------------\n");
			Linklist* p = L;
			return i;
		}
		p = p->next;
		i++;
	}
	
	printf("-------------------------不好意思，没有找到吖---------------------\n");

	
	return -1;
}

//按名称值删除节点
int list_delete_value(Linklist* L, datatype e)
{
	if (L == NULL)
	{
		return -1;
	}
	Linklist* p = L;
	while (p->next != NULL)
	{
		if (strcmp(p->next->data.name, e.name) == 0)
		{
			Linklist* q = p->next;
			p->next = q->next;
			free(q);
			L->len--;
			printf("-------------------------恭喜你，删除成功了哟----------------------\n");
			return 0;
		}
		p = p->next;
	}
	printf("-------------------------不好意思，没有找到啊--------------------\n");
	return -1;
}
//按名称修改节点
int list_update_value(Linklist* L, datatype e)
{
	if (L == NULL)
	{
		return -1;
	}
	Linklist* q = L;
	while (q->next!= NULL)
	{
		if (strcmp(q->next->data.name, e.name) == 0)
		{
			Linklist* p = node_buy(e);
			p->next = q->next->next;
			q->next = p;

			printf("---------------------修改成功了噢----------------------------\n");
			
			return 0;
		}
		q = q->next;
	}
	printf("需要修改教材，但是没有找到啊-------\n");
	return -1;
}

//输出链表
int list_show(Linklist* L)
{
	if (L == NULL)
	{
		return -1;
	}
	Linklist* p = L->next;
	while (p != NULL)
	{
		printf("--------------------------------------------------------\n");
		printf("教材名称：%s\n", p->data.name);
		printf("教材所属出版社：%s\n", p->data.publisher);
		printf("教材作者：%s\n", p->data.author);
		printf("教材出版年份：%d\n", p->data.year);
		//printf("教材订购数量：%d\n", p->data.buy_num);
		//printf("教材到货数量：%d\n", p->data.arrival_num);
		//printf("教材发放数量：%d\n", p->data.issue_num);
		p = p->next;
		printf("--------------------------------------------------------\n");
	}
	return 0;
}

//尾删
int list_delete_tail(Linklist* L)
{
	if (list_empty(L))
	{
		printf("链表为空\n");
		return -1;
	}
	Linklist* p = L;
	while (p->next->next != NULL)
	{
		p = p->next;
	}
	free(p->next);
	p->next = NULL;
	L->len--;
	return 0;
}
//销毁链表
void list_free(Linklist* L)
{
	if (NULL == L)
	{
		return;
	}
	while (L->next != NULL)
	{
		list_delete_tail(L);
	}

	free(L);
	L = NULL;

	printf("释放成功\n");
	return;

}