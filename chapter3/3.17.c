#include <stdlib.h>
#include <stdio.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT   10

typedef char ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

void InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));

	if(!S->base)
		exit(1);
	
	S->top = S->base;
	S->stacksize = LIST_INIT_SIZE;
}

void Push_Sq(SqStack *S, int e)
{
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc(S->base, (LIST_INIT_SIZE+LISTINCREMENT)  * sizeof(ElemType));
		
		if(!S->base)
			exit(1);

		S->top = S->base + S->stacksize;
	
		S->stacksize += LISTINCREMENT;
	}

	*(S->top) = e;
	S->top++;
}

void Pop_Sq(SqStack *S, int *e)
{
	if(S->top == S->base)
		exit(1);

	S->top--;
	*e = *(S->top);
}

int StackEmpty(SqStack S)
{
	if(S.top == S.base)
		return 1;
	else
		return 0;
}

void ClearStack_Sq(SqStack *S)
{
	S->top = S->base;
}

void DestroyStack_Sq(SqStack *S)
{
	free(S->base);

	S->top = NULL;
	S->base = NULL;
	S->stacksize = 0;
}

int Algo_3_17(SqStack *S, char *s)
{
	int e, i = 0;


	while(s[i] != '@' && s[i] != '&'){
		Push_Sq(S, s[i]);
		i++;
	}

	if(s[i] != '@' && s[i] == '&'){
		i++;
		printf("i = %d\n", i);
		printf("%c \n", s[i]);
		while(!StackEmpty(*S) && s[i] != '@'){
			Pop_Sq(S, &e);
			if(e != s[i]){
				printf("t");
				return 0;
			}
			i++;
		}
	}
	printf("i = %d\n", i);
	printf("%c \n", s[i]);
	if(s[i] == '@'){
		printf("tt");
		return 1;
	}
	else{
		printf("ttt");
		return 0;
	}
}

int main()
{
	SqStack S;
	char *s = "ab-c&c-b+a@";

	InitStack(&S);

	printf("判断s的序列是否满足要求\n");
	
	if(Algo_3_17(&S, s))
		printf("序列满足要求\n");
	else
		printf("序列不满足要求\n");

	ClearStack_Sq(&S);

	DestroyStack_Sq(&S);

	return 0;
}
