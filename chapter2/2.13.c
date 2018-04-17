/* 功能：返回元素 i 在链表中的位序号 */

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

void ListInsert(LinkList *L, int i, int e)
{
	int j = 0;
	LinkList p, q;		//p用来遍历链表 q用来当做新的结构体指针

	p = (*L);

	while(p && j<i-1){
		p = p->next;
		j++;
	}

	if(!p || j>i-1)
		exit(1);

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

/*					//这种算法会产生越界错误,原因是在于最后一个节点
void ListTraverse(LinkList L, void (Visit)(ElemType))
{
	LinkList p;
	
	p = L;

	while(p){
		p = p->next;		//最后一次循环遍历到链表外面了,因此产生越界错误
		Visit(p->data);
	}
}
*/

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

int Algo_2_13(LinkList L, int e)
{
	int j;
	LinkList p;
	
	p = L;

	while(p){
		p = p->next;
		if(p->data != e)
			j++;
		else
			return j+1;	
	}

	return 0;
}

int main()
{
	LinkList L;
	int i;

	if(ListInit(&L)){
		for(i=1; i<=10; i++)
			ListInsert(&L, i, 2*i);
	}
	printf("L : ");
	ListTraverse(L, PrintElem);
	printf("\n\n");

	printf("元素 10 在链表中的位置为: %d", Algo_2_13(L, 10));
	printf("\n");

	return 0;
}
