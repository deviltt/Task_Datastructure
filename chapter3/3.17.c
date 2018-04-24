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
		return -1;
}

int Algo_3_17(char *s)
{
	SqStack S;
	int e, i = 0;

	InitStack(&S);

	while(s[i] != '@' && s[i] != '&'){
		Push_Sq(&S, s[i]);
		i++;
	}

	if(s[i] != '@'){
		i++;
		while(!StackEmpty(S) && s[i] != '@'){
			Pop_Sq(&S, &e);
			if(e != s[i])
				return 0;
			i++;
		}
	}

	if(StackEmpty(S) && s[i] == '@')
		return 1;
	else
		return 0;
}

int main()
{
	char *s = "a+b-c&c-b+a@";

	printf("判断s的序列是否满足要求\n");
	
	if(Algo_3_17(s))
		printf("序列满足要求\n");
	else
		printf("序列不满足要求\n");

	return 0;
}
