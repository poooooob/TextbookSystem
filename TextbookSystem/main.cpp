#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"linklist.h"



int main(int argc, const char* argv[])
{
	Linklist* L = list_create();    //��������
	if (L == NULL)
	{
		printf("��������ʧ��\n");
		return 0;
	}
	int n = 0;
	menu(L, n);
	return 0;
}

