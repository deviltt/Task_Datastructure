/*****************************************************************************************
 * 函數功能：無頭結點鏈表 								 *
 *	     1. 表la中删除自第i个元素起共len个元素后，将它们插入到表lb中的第j个元素之前; *
 * 	     2. 在无头结点的动态单链表上实现线性表操作INSERT(L, i, b);                   *
 *           3. 实现线性表操作DELETE(L, i);						 *
 *****************************************************************************************/

#include <stdlib.h>
#include <stdio.h>

typedef int ElemType;

typedef struct LNode{
	struct LNode *next;
	ElemType data;
}LNode, *LinkList;

void ListInit(LinkList *L)
{
	*L = NULL;
}


void ListInsert(LinkList *L, int i, int e)
{
	LinkList p, q;
	int j = 1;

	q = (LinkList)malloc(sizeof(LNode));

	if(!q)
		exit(1);
	
	q->data = e;

	if(!(*L)){
		*L = q;
		p = q;
		q->next = NULL;
	}
	else{
		p = (*L);
		while(p && j < i-1){
			p = p->next;
			j++;	
		}

		q->next = p->next;
		p->next = q;
	}
}
	
/*	
void ListInsert(LinkList L, int i, int e)
{
	LinkList p, q;
	int j = 0;

	p = L;

	q = (LinkList)malloc(sizeof(ElemType));
	
	if(!q)
		exit(1);
	
	q->data = e;
	
	if(!L){
		p = q;
		L = q;
		q->next = NULL;
	}
	else{
		while(p && j<i-2){
			p = p->next;
			j++;
		}

		q->next = p->next;
		p->next = q;
	}
}
*/

void PrintElem(ElemType e)
{
	printf("%d ", e);
}

void ListTraverse(LinkList L, void (Visit)(ElemType))
{
	LinkList p;

	p = L;

	while(p){
		Visit(p->data);
		p = p->next;
	}
}

void Algo_2_16(LinkList *L1, LinkList *L2, int i, int j, int len)	//将la中第i个元素起一共len个元素连接到lb中第j个元素之前
{
	LinkList p, p_next, p_pre, q;

	int k1 = 1, k2 = 1;

	p = *L1;
	q = *L2;

	while(p && k1 < i-1){		//将指针p定位到第 i-1 个元素
		k1++;
		p = p->next;
	}
	
	p_pre = p;		
	p_next = p->next;

	while(p && k1 < i+len-1){	//将指针p定位到第 i+len-1 个元素 目的是方便后面 链接 的方便
		k1++;
		p = p->next;
	}

	while(q && k2 < j-1){		//将指针q定位到第 j-1 个元素
		k2++;
		q = q->next;
	}
	
	p_pre->next = p->next;
	p->next = q->next;
	q->next = p_next;
}

void Algo_2_17(LinkList *L, int i)
{
	LinkList p, q;
	int j = 1;

	p = *L;

	while(p && j < i-1){
		j++;
		p = p->next;
	}

	q = p->next;

	p->next = q->next;

	free(q);
}

int main()
{
	LinkList la, lb;
	int i;

	ListInit(&la);
	ListInit(&lb);

	for(i=1; i<=10; i++){
		ListInsert(&la, i, 2*i-1);
		ListInsert(&lb, i, 2*i);
	}	
	
	printf("沒有改變之前兩個鏈表：\n");
	printf("la: ");
	ListTraverse(la, PrintElem);
	printf("\n");
	printf("lb: ");
	ListTraverse(lb, PrintElem);
	printf("\n");

	printf("la 和 lb的操作互換: \n");
	Algo_2_16(&la, &lb, 2, 5, 4);

	printf("操作結束後的la, lb爲: \n");
	printf("la: ");
	ListTraverse(la, PrintElem);
	printf("\n");
	printf("lb: ");
	ListTraverse(lb, PrintElem);
	printf("\n");

	printf("delete the ith number in lb\n");
	Algo_2_17(&lb, 6);
	printf("the new lb is: ");
	ListTraverse(lb, PrintElem);
	printf("\n");

	return 0;
}
