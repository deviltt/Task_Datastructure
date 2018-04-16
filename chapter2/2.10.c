/* 刪除線性表第 i 個元素起的 k 個元素 */

#include <stdio.h>
#include <stdlib.h>

#define INCREMENT 10
#define LIST_INIT_SIZE 100

typedef int ElemType_Sq;

typedef struct{
	ElemType_Sq *base;	//線性表基地址
	int length;		//當前長度
	int list_init_size; 	//初始分配空間
}SqList;

int ListInit_Sq(SqList *L)
{
	(*L).base = (ElemType_Sq *)malloc(LIST_INIT_SIZE * sizeof(ElemType_Sq));

	if(!(*L).base)
		exit(1);

	(*L).length = 0;
	(*L).list_init_size = LIST_INIT_SIZE;

	return 1;
}

void ListInsert_Sq(SqList *L, int i, int e)
{
	ElemType_Sq *p, *q;
		
	if(i<0 || i>(*L).length + 1)	//加1的原因：也可以在最後一個元素位置插入一個值啊
		exit(1);
	
	if((*L).length > (*L).list_init_size){
		(*L).base = (ElemType_Sq *)realloc((*L).base, ((*L).list_init_size + INCREMENT) * sizeof(ElemType_Sq));

		if(!(*L).base)
			exit(1);

		(*L).list_init_size += INCREMENT;
	}

	q = &(*L).base[i-1];

	for(p = &(*L).base[(*L).length - 1]; p>=q; p--){	//加 "=" 的原因是 q 位置的元素也要後移
		*(p+1) = *p;
	}

	*q = e;
	(*L).length++;
}

void PrintElem(ElemType_Sq e)
{
	printf("%d ", e);
}

void ListTraverse_Sq(SqList L, void (Visit)(ElemType_Sq))
{
	int i;
	
	for(i=0; i<L.length; i++){
		Visit(L.base[i]);
	}
}

void Algo_2_10(SqList *L, int i, int k)
{
	int j;

	if(i<1 || i>(*L).length || k<0 || i+k-1 > (*L).length)
		exit(1);

	for(j=i+k; j<=(*L).length; j++)
		(*L).base[j-k-1] = (*L).base[j-1];

	(*L).length -= k;
}

int main()
{
	SqList L;
	int i;

	if(ListInit_Sq(&L)){
		for(i=1; i<20; i++){
			ListInsert_Sq(&L, i, i);
		}	
	}
			
	printf("當前線性表的元素爲: \n");
	ListTraverse_Sq(L, PrintElem);	
	printf("\n");

	printf("刪除第 5 個起的 10 個元素:\n");
	Algo_2_10(&L, 5, 10);
	printf("L = ");
	ListTraverse_Sq(L, PrintElem);
	printf("\n");

	return 0;
}
