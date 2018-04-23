#include <stdio.h>
#include <stdlib.h>

#define N 100

typedef int ElemType;
typedef enum{left, right} StackName;

typedef struct{
	ElemType s[N];
	int t[2];
}TWStack;

void StackInit(TWStack *S)
{
	(*S).t[left] = -1;
	(*S).t[right] = N;
}

void Push(TWStack *S, StackName name, ElemType e)
{
	if((*S).t[left] + 1 == (*S).t[right])
		exit(1);

	switch(name){
		case left:
			(*S).t[name]++;
			break;
		case right:
			(*S).t[name]--;
			break;
	}

	(*S).s[(*S).t[name]] = e;
}

void OutputStack(TWStack S, StackName name)
{
	int i;

	switch(name){
		case left:
			for(i=0; i<=S.t[name]; i++)
				printf("%d ", S.s[i]);
			break;
		case right:
			for(i=N-1; i>=S.t[name]; i--)
				printf("%d ", S.s[i]);
			break;
	}
}

void Pop(TWStack *S, StackName name, int *e)
{
	switch(name){
		case left:
			if((*S).t[name] == -1)
				exit(1);
			*e = (*S).s[(*S).t[name]];
			(*S).t[name]--;
			break;
		case right:
			if((*S).t[name] == N)
				exit(1);
			*e = (*S).s[(*S).t[name]];
			(*S).t[name]++;
			break;
	}
}

int main()
{
	TWStack S;
	int i, x;

	printf("初始化栈: ");
	StackInit(&S);
	printf("\n");

	printf("向栈两端压入元素: ");
	for(i=1; i<=5; i++){
		Push(&S, left, i);
		Push(&S, right, 2*i);
	}

	printf("左栈中的元素: ");
	OutputStack(S, left);
	printf("\n");
	printf("右栈中的元素: ");
	OutputStack(S, right);
	printf("\n");

	printf("分别弹出两个栈的栈顶元素: \n");	
	Pop(&S, left, &x);
	printf("左栈的栈顶元素为: %d\n", x);
	Pop(&S, right, &x);
	printf("右栈的栈顶元素为: %d\n", x);
	
	printf("左栈中的元素: ");
	OutputStack(S, left);
	printf("\n");
	printf("右栈中的元素: ");
	OutputStack(S, right);
	printf("\n");

	return 0;
}
