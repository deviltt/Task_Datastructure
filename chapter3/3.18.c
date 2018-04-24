#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT   10

typedef char ElemType;

typedef struct{
	ElemType *base;
	ElemType *top;
	int stacksize;
}SqStack;

int StackEmpty(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else 
		return 0;
}

void InitStack(SqStack *S)
{
	S->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));

	if(!S->base)
		exit(1);

	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void Push_Sq(SqStack *S, int e)
{
	if(S->top - S->base >= S->stacksize){
		S->base = (ElemType *)realloc(S->base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(ElemType));
		if(!S->base)
			exit(1);
		S->top = S->base + S->stacksize;
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

int Algo_3_17(char *s)
{
	SqStack S;
	int i = 0, e;

	InitStack(&S);

	while(s[i]){
		switch(s[i]){
			case '(':
			case '[':
			case '{':
				Push_Sq(&S, s[i]);
				break;

			case ')':
			case ']':
			case '}':
				if(StackEmpty(S))
					return 0;
				Pop_Sq(&S, &e);
				break;
		}
		i++;
	}

	if(StackEmpty(S))
		return 1;
	else
		return 0;	
}

int main()
{
	char *s = "(2-3)*(3+1)]{}";

	printf("判断字符串的'()' '[]' '{}'是否匹配\n");

	if(Algo_3_17(s))
		printf("匹配\n");
	else
		printf("不匹配\n");

	return 0;
}
