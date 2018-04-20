#include <stdlib.h>
#include <stdio.h>

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
	LinkList p, q;
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
	printf("%-2d ", e);
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

void Algo_2_23(LinkList La, LinkList Lb, LinkList *Lc)
{
	LinkList p, q, pre_p, pre_q;

	*Lc = La;

	p = La->next;
	q = Lb->next;

	while(p && q){
		p->next = q;
		q->next = p->next;
		pre_p = p;
		pre_q = q;
		p = p->next;
		q = q->next;
	}

	if(!p){
		pre_p->next = q;
	}
	
	if(!q){
		pre_q->next = p;
	}
}

int main()
{
	LinkList La, Lb, Lc;
	int i;

	if(ListInit(&La) && ListInit(&Lb)){
		for(i=1; i<8; i++)
			ListInsert(La, i, 2*i-1);
		for(i=1; i<7; i++)
			ListInsert(Lb, i, 2*i);
	}

	printf("兩個初始鏈表分別爲：\n");
	printf("La = ");
	ListTraverse(La, PrintElem);
	printf("\n");
	printf("Lb = ");
	ListTraverse(Lb, PrintElem);
	printf("\n");

	Algo_2_23(La, Lb, &Lc);

	printf("轉換後的新鏈表爲：\n");
	printf("Lc = ");
	ListTraverse(Lc, PrintElem);
	printf("\n");
}
