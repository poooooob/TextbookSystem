#ifndef __LINKLIST_H__
#define __LINKLIST_H__
typedef struct Node1
{
	char name[20];     //�̲�����
	char publisher[100];//������
	char author[10];   //����
	int year;          //����ʱ��
	char buy_name[20]; //������
	int buy_num;       //��������
    int arrival_num;   //��������
	char issue_name[20];//������
	int issue_num;     //��������
}Node1;                //�̲���Ϣ

typedef Node1 datatype;
typedef struct Node
{
	union {
		datatype data;
		int len;
	};
	struct Node* next;
}Linklist;             //����


//����
Linklist* list_create();
//�п�
int list_empty(Linklist* L);
//����
int list_show(Linklist* L);
//��㺯��
Linklist* node_buy(datatype e);
//β��
int list_insert_tail(Linklist* L, datatype e);
//βɾ
int list_delete_tail(Linklist* L);
//��ֵ����
int list_search_value(Linklist* L, datatype e);
//��ֵ�޸�
int list_update_value(Linklist* L, datatype e);
//��������
void list_free(Linklist* L);
//��ֵɾ��
int list_delete_value(Linklist* L, datatype e);

//�˵�
void menu(Linklist* L, int n);
//1.��ӽ̲�
int Textbook_input(Linklist* L);
//2.ɾ���̲�
int Textbook_delete(Linklist* L);
//3.�޸Ľ̲�
int Textbook_update(Linklist* L);
//4.��ѯ�̲�
int Textbook_search(Linklist* L);
//5.�̲Ķ�������
int Textbook_buy(Linklist* L);
//6.�̲ĵ�������
int Textbook_arrival(Linklist* L);
//7.�̲ķ��Ź���
int Textbook_issue(Linklist* L);
//8.��������ͳ�ƽ̲�
int Textbook_count(Linklist* L);
//9.������ʱ��ͳ�ƽ̲�
int Textbook_count_year(Linklist* L);
//10��������н̲���Ϣ
int Textbook_show(Linklist* L);
//11.�������еĽ̲���Ϣд���ļ�
int Textbook_write(Linklist* L);


#endif	
