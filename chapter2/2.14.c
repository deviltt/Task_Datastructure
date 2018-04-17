#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode{
	struct LNode *next;
	ElemType data;
}LNode, *LinkList;

void PrintElem(ElemType e)
{
	printf("%d ", e);
}

int ListInit(LinkList *L)
{
	(*L) = (LinkList)malloc(sizeof(LNode));

	if(!(*L))
		exit(1);

	(*L)->next = NULL;
//	(*(*L)).next = NULL;
	
	return 1;
}

void ListInsert(LinkList L, int i, int e)
{
	LinkList p, q;
	int j = 0;

	p = L;

	while(p && j < i-1){
		p = p->next;
		j++;
	}

	if(!p || j > i-1)
		exit(1);

	q = (LinkList)malloc(sizeof(LNode));

	if(!q)
		exit(1);

	q->data = e;
	q->next = p->next;
	p->next = q;
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

int Algo_2_14(LinkList L)
{
	int i = 0;
	LinkList p;

	p = L->next;
	
	while(p){
		i++;
		p = p->next;
	}

	return i;
}

int main()
{
	LinkList L;
	int i;

	if(ListInit(&L)){
		for(i=1; i<10; i++)
			ListInsert(L, i, 2*i);
	}

	printf("\n");
	printf("L: ");
	ListTraverse(L, PrintElem);
	printf("\n\n");

	printf("线性表 L 的长度为 %d\n", Algo_2_14(L));
	printf("\n");

	return 0;
}
