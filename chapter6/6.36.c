#include <stdlib.h>
#include <stdio.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int TElemType;

typedef struct BitNode{
        struct BitNode *lchild;
        struct BitNode *rchild;
        TElemType data;
}BitNode;

typedef BitNode * BiTree;

typedef struct Stack{
	BiTree top;
	BiTree base;
	int stacksize;
}SqStack;

void InitStack(SqStack *S)
{
	S->base = (BiTree *)malloc(STACK_INIT_SIZE * sizeof(BiTree));

	if(!S->base)
		exit(1);

	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack *S, char ch)
{
	if(S->top - S->base >= S->stacksize){
		S->base = (char *)realloc(S->base, (STACK_INIT_SIZE + STACKINCREMENT) * sizeof(char));

		if(!S->base)
			exit(1);
	
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}

	*(S->top) = ch;
	S->top++;
}

void Pop(SqStack *S, char *e)
{
	if(S->top == S->base)
		return 0;

	S->top--;
	*e = *(S->top);
}

void CreateBiTree(BiTree *T)
{
        char string;
	
	scanf("%c", &string);


                if(string == '^')
                        *T = NULL;
                else{
                        *T = (BiTree)malloc(sizeof(BitNode));

                        if(!(*T))
                                exit(1);
                        (*T)->data = string;
                        CreateBiTree(&(*T)->lchild);
                        CreateBiTree(&(*T)->rchild);
                }
       
}

void PreOrderBiTree(BiTree T)
{
        if(T){
                printf("%c ", T->data);
                PreOrderBiTree(T->lchild);
                PreOrderBiTree(T->rchild);
        }
}

void InOrderBiTree(BiTree T)
{
	if(T){
		InOrderBiTree(T->lchild);
		printf("%c ", T->data);
		InOrderBiTree(T->rchild);
	}
}

void PostOrderBiTree(BiTree T)
{
	if(T){
		PostOrderBiTree(T->lchild);
		PostOrderBiTree(T->rchild);
		printf("%c ", T->data);
	}
}

void nPreOrderBiTree(SqStack S, BiTree T)
{
	if(T){
		printf("%c ", T->data);
		Push(&S, T->lchild);
	}
}

int main()
{
        BiTree B1, B2, B3;
	SqStack S;
	
//      char *b1 = "ABD^^E^^C^^";
        
        printf("创建二叉树 (先序序列) B1: ABD^^E^^C^^...\n");
        printf("                      B2: FGH^^I^^J^^...\n");
        printf("                      B3: KLM^^N^^OP^^^...\n");

        InitStack(&S);

        CreateBiTree(&B1);
//	CreateBiTree(&B2);
//	CreateBiTree(&B3);

	printf("递归形式遍历二叉树结果:\n");
        PreOrderBiTree(B1);
	printf("\n");
	InOrderBiTree(B1);
	printf("\n");
	PostOrderBiTree(B1);
	printf("\n");

	printf("非递归形式遍历二叉树结果:\n");
	nPreOrderBiTree(S, B1);
	printf("\n");
        nInOrderBiTree(B1);
        printf("\n");
        nPostOrderBiTree(B1);
        printf("\n");

        return 0;
}
