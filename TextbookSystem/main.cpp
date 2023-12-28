#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"linklist.h"



int main(int argc, const char* argv[])
{
	Linklist* L = list_create();    //创建链表
	if (L == NULL)
	{
		printf("创建链表失败\n");
		return 0;
	}
	int n = 0;
	menu(L, n);
	return 0;
}

