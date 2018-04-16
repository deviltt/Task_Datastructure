#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define LIST_INIT_SIZE 100

typedef int ElemType;

typedef struct{
	ElemType *base;
	int length;
	int listsize;
}SqList;

int ListInit_Sq(SqList *L)
{
	(*L).base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	
	if(!(*L).base)
		exit(1);

	(*L).length = 0;
	(*L).listsize = LIST_INIT_SIZE;
}

void ListInsert_Sq(SqList *L, int i, int e)
{
	ElemType *p, *q;
		
	if(i < 0 || i > (*L).length+1)
		exit(1);
	if((*L).length >= (*L).listsize){
		(*L).base = (ElemType *)realloc((*L).base, ((*L).listsize + (*L).length) * sizeof(ElemType));
	
		if(!(*L).base)
			exit(1);

		(*L).listsize += INCREMENT;
	}

	q = &(*L).base[i-1];

	for(p = &(*L).base[(*L).length-1]; p >= q; p--)
		*(p+1) = *p;

	*q = e;

	(*L).length++;
}

void PrintElem(ElemType e)
{
	printf("%d ", e);
}

void ListTraverse_Sq(SqList L, void (Visit)(ElemType))
{
	int i;
	
	for(i=0; i<L.length; i++)
		Visit(L.base[i]);
}

void Algo_2_11(SqList *L, int e)
{
	ElemType *p;
	int i;
	
	if(!(*L).length)	//the sequence is empty
		exit(1);

	if((*L).length >= (*L).listsize){
		(*L).base = (ElemType *)realloc((*L).base, ((*L).listsize + (*L).length) * sizeof(ElemType));
	
		if(!(*L).base)
			exit(1);
	
		(*L).listsize += INCREMENT;
	}
	
	for(i=(*L).length; i>1; i--){
		if((*L).base[i-1] > e)
			(*L).base[i] = (*L).base[i-1];
		else
			break;
	}

	(*L).base[i] = e;

	(*L).length++;
}

int main()
{
	SqList L;
	int i;

	if(ListInit_Sq(&L)){
		for(i=1; i<=10; i++)
			ListInsert_Sq(&L, i, 2*i);
	}
	printf("L: ");
	ListTraverse_Sq(L, PrintElem);
	printf("\n");

	Algo_2_11(&L, 5);
	printf("the new L: ");
	ListTraverse_Sq(L, PrintElem);
	printf("\n");
	
	return 0;
}
