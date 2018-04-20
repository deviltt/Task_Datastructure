/*
	use of function: reverse the list sequence
*/

#include <stdlib.h>
#include <stdio.h>

#define INCREMENT 10
#define LIST_INIT_SIZE 100

typedef int ElemType;

typedef struct{
	ElemType *base;
	int length;
	int listsize;
}SqList;

int ListInit(SqList *L)
{
	(*L).base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	
	if(!(*L).base)
		exit(1);

	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;

	return 1;
}

void ListInsert_Sq(SqList *L, int i, int e)
{
	ElemType *p, *q;

	if(i > (*L).length + 1 || i < 1)	//the reason must remember
		exit(1); 
	
	if((*L).length > (*L).listsize){
		(*L).base = (ElemType *)realloc((*L).base, (LIST_INIT_SIZE + INCREMENT) * sizeof(ElemType));

		(*L).listsize += INCREMENT;
	}

	q = &(*L).base[i-1];

	for(p = &(*L).base[(*L).length-1]; p >= q; p--)
		*(p+1) = *p;

	*q = e;
	
	(*L).length++;
}

void PrintElem(int e)
{
	printf("%d ", e);
}

void ListTraverse_Sq(SqList L, void (Visit)(ElemType))
{
	int i;
	
	for(i=0; i<L.length; i++)
		Visit(L.base[i]);
}

void Algo_2_21(SqList L)
{
	ElemType tmp;
	int j;
	
	if(L.length == 0)
		exit(1);

	for(j = 0; j < L.length / 2; j++){
		tmp = L.base[j];
		L.base[j] = L.base[L.length-j-1];
		L.base[L.length-j-1] = tmp;
	}
}

int main()
{
	SqList L;
	int i;

	if(ListInit(&L)){
		for(i=1; i<10; i++)
			ListInsert_Sq(&L, i, i);
	}
	
	printf("L = ");
	ListTraverse_Sq(L, PrintElem);
	printf("\n");	
	
	printf("after reverse: ");
	Algo_2_21(L);
	ListTraverse_Sq(L, PrintElem);
	printf("\n");

	return 0;
}
