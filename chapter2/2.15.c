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

	while(p && j > i-1){
		p = p->next;
		j++;
	}

//	if(!p || j > i-1)
//		exit(1);

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

	if(!L)
		exit(1);
	else
		p = L->next;
	
	while(p){
		Visit(p->data);
		p = p->next;
	}
}

void Algo_2_15(LinkList ha, LinkList hb, LinkList *hc)
{
	LinkList pa, pb;

	if(ha && hb){
		pa = ha;
		pb = hb;

		while(pa->next && pb->next){
			pa = pa->next;
			pb = pb->next;
		}

		if(!pa->next){
			*hc = ha;
			pa->next = hb->next;
		}

		if(!pb->next){
			*hc = hb;
			pb->next = ha->next;
		}
	}
}

int main()
{
	LinkList ha, hb, hc;
	int i;

	if(ListInit(&ha) && ListInit(&hb) && ListInit(&hc)){
		for(i=1; i<5; i++)
			ListInsert(ha, i, i);
		for(i=5; i<7; i++)
			ListInsert(hb, i, i);
	}

	printf("\nha = ");
	ListTraverse(ha, PrintElem);
	printf("\nhb = ");
	ListTraverse(hb, PrintElem);
	printf("\n");

	Algo_2_15(ha, hb, &hc);	
	printf("链接后的链表为: ");
	ListTraverse(hc, PrintElem);
	printf("\n");
	
	return 0;
}
