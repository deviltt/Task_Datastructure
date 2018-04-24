#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef char ElemType;

typedef struct{
	ElemType *top;
	ElemType *base;
	int stacksize;
}SqStack;

void InitStack(SqStack *S)
{
	(*S).base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));

	if(!(*S).base)
		exit(1);

	(*S).top = (*S).base;
	(*S).stacksize = STACK_INIT_SIZE;
}

void Push_Sq(SqStack *S, char s)
{
	if((*S).top - (*S).base >= (*S).stacksize){
		(*S).base = (ElemType *)realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(ElemType));
		
		if(!(*S).base)
			exit(1);

		(*S).top = (*S).base + (*S).stacksize;
		(*S).stacksize += STACKINCREMENT;
	}

	*(S->top) = s;
	(*S).top++;
}

void Pop_Sq(SqStack *S, char *s)
{
	if((*S).top == (*S).base)
		exit(1);

	(*S).top--;
	*s = *(S->top);
}

int StackEmpty_Sq(SqStack S)
{
	if(S.base == S.top)
		return 1;
	else
		return 0;
}

void Algo_3_16(char *En, char *Con)
{
	SqStack S;
	int i=0, j=0;
	char e;	

	InitStack(&S);
	
	while(En[i]){
		if(En[i] == 'H'){
			Push_Sq(&S, En[i]);
			Con[j++] = 'I';
		}
		
		if(En[i] == 'S'){
			Push_Sq(&S, En[i]);
			Pop_Sq(&S, &e);
			Con[j++] = 'I';
			Con[j++] = 'O';
		}

		i++;
	}

	while(!StackEmpty_Sq(S)){
		Pop_Sq(&S, &e);
		Con[j++] = 'O';
	}

	Con[j] = '\0';
}

void Dispatch_3_16(char *En, char *Ex, char *Con)
{
	SqStack S;
	int i, j, k;
	char e;

	InitStack(&S);

	i = j = k = 0;

	while(Con[i]){
		if(Con[i] == 'I')
			Push_Sq(&S, En[j++]);
		
		if(Con[i] == 'O'){
			Pop_Sq(&S, &e);
			Ex[k++] = e;
		}

		i++;
	}

//	if(!Con[i] && (En[i] || StackEmpty_Sq(S)))
//		exit(1);

	Ex[k] = '\0';
}

int main()
{
	char *En = "HSHHSHHHSHSSSHS";
	char Ex[100], Con[100];

	printf("入口在左,出口在右\n");
	printf("初始车厢排列为:\nEn = ");
	printf("%s\n", En);
	printf("\n");

	printf("生成调度序列:\n");
	Algo_3_16(En, Con);
	printf("调度序列为:\n");
	printf("%s\n", Con);
	printf("\n");

	printf("根据序列进行车厢调度:\n");
	Dispatch_3_16(En, Ex, Con);
	printf("调度完成后车厢的序列:\n");
	printf("%s\n", Ex);
	printf("\n");

	return 0;
}
