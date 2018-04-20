/****************************************************
   線性表遞增排列				    
   函數功能：
	1. 刪除表中元素相同的值；
	2. 將在給定範圍內的所有值刪除；
	3. 打出操作後的線性表與初始線性表進行對比；
*****************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

int ListInit(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));

	if(!(*L))
		exit(1);

	(*L)->next = NULL;

	return 1;
}

void ListInsert(LinkList L, int i, int e)
{
	LinkList p, q;
	int j = 0;

	if(i < 0)
		exit(1);

	p = L;

	while(p && j<i-1){
		p = p->next;
		j++;
	}

	q = (LinkList)malloc(sizeof(LNode));

	if(!q)
		exit(1);

	q->data = e;

	q->next = p->next;
	p->next = q;
}

void PrintElem(ElemType e)
{
	printf("%d ", e);
}

void ListTraverse(LinkList L, void (Visit)(ElemType))
{
	LinkList p;

	p = L;

	while(p){
		p = p->next;
		Visit(p->data);
	}
}

int main()
{
	LinkList L;
	int a[] = {1,2,2,3,4,5,6,6,6,8};
	int i, min = 2, max = 7;

	if(ListInit(&L)){
		for(i=0; i<10; i++)
			ListInsert(L, i+1, a[i]);
	}

	printf("初始創建的線性表爲：\n");
	ListTraverse(L, PrintElem);
	printf("\n");
/*
	printf("將相同的元素刪除：\n");
	Algo_2_19(L);
	ListTraverse(L, PrintElem);
	printf("\n");

	printf("將指定範圍內的元素刪除：\n");
	Algo_2_20(L, min, max);
	ListTraverse(L, PrintElem);*/
	printf("\n");

	return 0;
}
