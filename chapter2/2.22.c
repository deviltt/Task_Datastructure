/* 函數功能：使用頭插法實現單鏈表的逆置 */

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	struct LNode *next;
	ElemType data;
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
	LinkList p,  q;
	int j = 0;

	p = L;

	while(p && j < i-1){
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

	p = L->next;

	while(p){
		Visit(p->data);
		p = p->next;
	}
}

void Algo_2_22(LinkList L)
{
	LinkList p, pre;

	p = L->next;
	L->next = NULL;

	while(p){
		pre = p;
		p = p->next;
		pre->next = L->next;
		L->next = pre;
	}
}

int main()
{
	LinkList L;
	int i;

	if(ListInit(&L)){
		for(i = 1; i < 10; i++)
			ListInsert(L, i, i);
	}

	printf("初始鏈表 L :\n");
	ListTraverse(L, PrintElem);
	printf("\n");

	printf("倒置後的鏈表爲 L :\n");
	Algo_2_22(L);
	ListTraverse(L, PrintElem);
        printf("\n");	

	return 0;
}
