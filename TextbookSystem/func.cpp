#include"linklist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>


//�˵�
void menu(Linklist* L, int n)
{
	while (1)
	{
		printf("-----------------------------------�̲Ĺ���ϵͳ-----------------------------\n");
		printf("----------                         0.�˳�                        -----------\n");
		printf("----------                         1.��ӽ̲�                    ----------\n");
		printf("----------                         2.ɾ���̲�                    ----------\n");
		printf("----------                         3.�޸Ľ̲�                    --------- \n");
		printf("----------                         4.���ҽ̲�                    ----------\n");
		printf("----------                         5.�̲Ķ�������                ----------\n");
		printf("----------                         6.�̲ĵ�������                -----------\n");
		printf("----------                         7.�̲ķ��Ź���                -----------\n");
		printf("----------                         8.��������ͳ������            ------------\n");
		printf("----------                         9.��ʱ��ͳ������              -------------\n");
		printf("----------                         10.�鿴���н̲���Ϣ           ------------\n");
		printf(" ---------                         11.���������Ϣ���ļ���       --------------\n");
		printf(" ----------------------------------��ѡ����----------------------------------\n");
		scanf_s("%d", &n);

		switch (n)
		{
		case 0:
			printf("-------------------------�˳�----------------------\n");
			return;
			break;

		case 1:
			printf("-----------------------��ӽ̲�--------------------\n");
			Textbook_input(L);
			break;
		case 2:
			printf("-----------------------ɾ���̲�--------------------\n");
			Textbook_delete(L);
			break;
		case 3:
			printf("-----------------------�޸Ľ̲�---------------------\n");
			Textbook_update(L);
			break;
		case 4:
			printf("-----------------------���ҽ̲�-----------------------\n");
			Textbook_search(L);
			break;
		case 5:
			printf("--------------------�̲Ķ�������----------------------\n");
			Textbook_buy(L);
			break;
		case 6:
			printf("--------------------�̲ĵ�������---------------------\n");
			Textbook_arrival(L);
			break;
		case 7:
			printf("--------------------�̲ķ��Ź���---------------------\n");
			Textbook_issue(L);
			break;
		case 8:
			printf("-------------------��������ͳ������---------------------\n");
			Textbook_count(L);
			break;
		case 9:
			printf("--------------------��ʱ��ͳ������------------------------\n");
			Textbook_count_year(L);
			break;
		case 10:
			printf("--------------------������н̲���Ϣ------------------------\n");
			Textbook_show(L);
			break;
		case 11:
			printf("--------------------���������Ϣ���ļ���------------------------\n");
			Textbook_write(L);
			break;
		default:
			printf("�����������������\n");
			break;
		}
	}
}
//1.��ӽ̲�
int Textbook_input(Linklist* L)
{
	datatype e;
	printf("��������Ҫ��ӵĽ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name,20);
	printf("������̲�����������\n");
	scanf_s("%s", &e.publisher,100);
	printf("���������ߣ�\n");
	scanf_s("%s", &e.author,10);
	printf("������̲ĳ������\n");
	scanf_s("%d", &e.year);

	//Linklist* p = node_buy(e);	//�����ڵ�
	list_insert_tail(L, e);    //β��
	return 0;
}
//2.��ֵɾ���̲�
int Textbook_delete(Linklist* L)
{
	datatype e;
	printf("��������Ҫɾ���Ľ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name,20);
	list_delete_value(L, e);    //��ֵɾ��
	return 0;
}
//3.�޸Ľ̲�
int Textbook_update(Linklist* L)
{
	datatype e;
	printf("��������Ҫ�޸ĵĽ̲���Ϣ��\n");
	printf("������̲������ƣ��򱣳ֲ��䣩\n");
	scanf_s("%s", e.name,20);
	printf("�������³����� ���򱣳ֲ��䣩\n");
	scanf_s("%s", &e.publisher,20);
	printf("�������³�����ݣ��򱣳ֲ��䣩\n");
	scanf_s("%d", &e.year);
	printf("�����������ߣ��򱣳ֲ��䣩\n");
	scanf_s("%s", &e.author,10);
	//printf("�����붩��������Ĭ��-1����");
	//scanf_s("%d", &e.buy_num);
	//e.buy_num = -1;
	//printf("�����뵽��������Ĭ��-1����");
	//scanf_s("%d", &e.arrival_num);
	//e.arrival_num = -1;
	//printf("�����뷢��������Ĭ��-1����");
	//scanf_s("%d", &e.issue_num);
	//ʹ��һ���½ڵ����洢���ĺ����Ϣ
	//Linklist* p = node_buy(e);
	list_update_value(L, e);
	return 0;
}
//4.���ҽ̲�
int Textbook_search(Linklist* L)
{
	datatype e;
	printf("��������Ҫ���ҵĽ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name,20);
	list_search_value(L, e);
	return 0;
}
//5.�̲Ķ�������
int Textbook_buy(Linklist* L)
{
	datatype e;
	printf("��������Ҫ�����Ľ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name, 20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;

	}
	printf("�����붩���ˣ�\n");
	scanf_s("%s", &e.buy_name,20);
	strcpy_s(p->data.buy_name, e.buy_name);
	printf("�����붩������\n");
	scanf_s("%d", &e.buy_num);
	p->data.buy_num = e.buy_num;
	printf("�Ѿ�����%d���̲�,�������ǣ�%s\n", e.buy_num,e.buy_name);
	return 0;
}
//6.�̲ĵ�������
int Textbook_arrival(Linklist* L)
{
	datatype e;
	printf("�����뵽���Ľ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name, 20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;
	}
	printf("�����뵽������\n");
	scanf_s("%d", &e.arrival_num);
	p->data.arrival_num = e.arrival_num;
 	printf("----------------------------�Ѿ�������%d���̲�-------------------\n", e.arrival_num);
	return 0;
}
//7.�̲ķ��Ź���
int Textbook_issue(Linklist* L)
{
	datatype e;
	printf("��������Ҫ���ŵĽ̲���Ϣ��\n");
	printf("������̲�����\n");
	scanf_s("%s", e.name,20);
	int count = list_search_value(L, e);
	Linklist* p = L;
	for (int i = 0;i < count;i++)
	{
		p=p->next;
	}
	printf("�����뷢���ˣ�\n");
	scanf_s("%s", &e.issue_name,20);
	strcpy_s(p->data.issue_name, e.issue_name);
	printf("�����뷢������\n");
	scanf_s("%d", &e.issue_num);
	p->data.issue_num = e.issue_num;
	printf("�Ѿ�����%d���̲�,�������ǣ�%s\n",e.issue_num,e.issue_name);
	return 0;
}
//8.��������ͳ�ƽ̲�
int Textbook_count(Linklist* L)
{
	//���������ѳ�������ͬ�Ľ̲ĵĶ������������������Լ����������ֱ���Ӻ����
	
	char pub[20];
	printf("��������Ҫ���ļҳ�����ͳ��������\n");
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
	printf("--------------�ó����綩������Ϊ%d����������Ϊ%d����������Ϊ%d----------------\n", count_buy, count_arrival, count_issue);
	return 0;
}
//9.�����ͳ�ƽ̲�
int Textbook_count_year(Linklist* L)
{
	//���������������ͬ�Ľ̲ĵĶ������������������Լ������������
	int year;
	printf("��������Ҫ����һ��ͳ��������\n");
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
	printf("���궩������Ϊ%d����������Ϊ%d����������Ϊ%d\n", count_buy, count_arrival, count_issue);
	return 0;
}
//10.������н̲���Ϣ
int Textbook_show(Linklist* L)
{
	list_show(L);
	return 0;
}
//11.�������е�����д���ļ�
int Textbook_write(Linklist* L)
{
	FILE* fp = fopen("Textbook.txt", "w");
	if (NULL == fp)
	{
		printf("�ļ���ʧ��\n");
		return -1;
	}
	Linklist* p = L;
	while (p != NULL)
	{
		fprintf(fp, "--------------------------------------------------------------------------------------------------------------------");
		fprintf(fp, "������%s ���ߣ�%s �����磺%s �������ڣ�%d \n", p->data.name, p->data.author, p->data.publisher, p->data.year);
		fprintf(fp,"�����ˣ�%s,����������%d������������%d,�����ˣ�%s,����������%d\n", p->data.buy_name, p->data.buy_num,p->data.arrival_num,p->data.issue_name,p->data.issue_num);
		fprintf(fp,"---------------------------------------------------------------------------------------------------------------------");
		p = p->next;
	}
	fclose(fp);
	return 0;
}


//����
Linklist* list_create()
{
	Linklist* L = (Linklist*)malloc(sizeof(Linklist));
	if (NULL == L)
	{
		printf("����ʧ��\n");
		return NULL;
	}

	//��ʼ��
	L->len = 0;
	L->next = NULL;

	printf("�����ɹ�\n");
	return L;
}
//�п�
int list_empty(Linklist* L)
{
	if (0 == L->len)
	{
		printf("����Ϊ��\n");
		return 1;
	}
}

//��������ڵ㺯��
Linklist* node_buy(datatype e)
{
	Linklist* p = (Linklist*)malloc(sizeof(Linklist));
	if (NULL == p)
	{
		printf("�ڵ�����ʧ��\n");
		return NULL;
	}
	strcpy_s(p->data.name, e.name);
	strcpy_s(p->data.publisher, e.publisher);
	strcpy_s(p->data.author, e.author);
	p->data.year = e.year;
	p->data.buy_num = 0;           //��������,Ĭ��Ϊ0
	p->data.arrival_num= 0;        //��������,Ĭ��Ϊ0
	p->data.issue_num = 0;         //��������,Ĭ��Ϊ0
	strcpy_s(p->data.buy_name,"����");        //������,Ĭ��
	strcpy_s(p->data.issue_name,"����");     //������,Ĭ��
	p->next = NULL;

	return p;
}

//β�巨,����ڵ�
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
	printf("------------------------------------��ϲ�㣬��ӳɹ���Ӵ--------------------------\n");
	return 0;
}


//���̲������������в�ѯ������̲���Ϣ
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
			printf("-----------------�ҵ���!�������ǽ̲���Ϣ------------------\n");
			printf("�̲����ƣ�%s\n", p->next->data.name);
			printf("�����磺%s\n", p->next->data.publisher);
			printf("���ߣ�%s\n", p->next->data.author);
			printf("������ݣ�%d\n", p->next->data.year);
			printf("����������%d�������ˣ�%s\n", p->next->data.buy_num,p->next->data.buy_name);
			printf("����������%d\n", p->next->data.arrival_num);
			printf("����������%d,�����ˣ�%s\n", p->next->data.issue_num,p->next->data.issue_name);
			printf("----------------------------------------------------------\n");
			Linklist* p = L;
			return i;
		}
		p = p->next;
		i++;
	}
	
	printf("-------------------------������˼��û���ҵ�߹---------------------\n");

	
	return -1;
}

//������ֵɾ���ڵ�
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
			printf("-------------------------��ϲ�㣬ɾ���ɹ���Ӵ----------------------\n");
			return 0;
		}
		p = p->next;
	}
	printf("-------------------------������˼��û���ҵ���--------------------\n");
	return -1;
}
//�������޸Ľڵ�
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

			printf("---------------------�޸ĳɹ�����----------------------------\n");
			
			return 0;
		}
		q = q->next;
	}
	printf("��Ҫ�޸Ľ̲ģ�����û���ҵ���-------\n");
	return -1;
}

//�������
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
		printf("�̲����ƣ�%s\n", p->data.name);
		printf("�̲����������磺%s\n", p->data.publisher);
		printf("�̲����ߣ�%s\n", p->data.author);
		printf("�̲ĳ�����ݣ�%d\n", p->data.year);
		//printf("�̲Ķ���������%d\n", p->data.buy_num);
		//printf("�̲ĵ���������%d\n", p->data.arrival_num);
		//printf("�̲ķ���������%d\n", p->data.issue_num);
		p = p->next;
		printf("--------------------------------------------------------\n");
	}
	return 0;
}

//βɾ
int list_delete_tail(Linklist* L)
{
	if (list_empty(L))
	{
		printf("����Ϊ��\n");
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
//��������
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

	printf("�ͷųɹ�\n");
	return;

}