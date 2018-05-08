#include <stdio.h>
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef char SElemType_Sq;

typedef struct{
        SElemType_Sq *base;
        SElemType_Sq *top;
        int stacksize;
}SqStack;

void InitStack_Sq(SqStack *S)
{
        S->base = (SElemType_Sq *)malloc(STACK_INIT_SIZE * sizeof(SElemType_Sq));

        if(!S->base)
                exit(1);

        S->top = S->base;
        S->stacksize = STACK_INIT_SIZE;
}

void Push(SqStack *S, char a)
{
        if(S->top - S->base > S->stacksize){
                S->base = (SElemType_Sq *)realloc(S->base, (S->stacksize + STACKINCREMENT)*sizeof(SElemType_Sq));
                if(!S->base)
                        exit(1);
                S->top = S->base + S->stacksize;
                S->stacksize += STACKINCREMENT;
        }

        *(S->top) = a;
        S->top++;
}

int StackEmpty(SqStack S)
{
        if(S.top == S.base)
                return 1;
        else
                return 0;
}

void Pop_Sq(SqStack *S, char *e)
{
        if(S->top == S->base)
                exit(1);

	S->top--;
	*e = *(S->top);
}

int Matching(char a, char b)
{
        switch(a){
                case '(':
                        if(b != ')')
                                return 0;
                        break;
                case '[':
                        if(b != ']')
                                return 0;
                        break;
                case '{':
                        if(b != '}')
                                return 0;
                        break;
       
                default:
                        return 0;
        }
        return 1;
}

int Algo_3_19(char *s)
{
        SqStack S;
        SElemType_Sq e;
        int i = 0;

        InitStack_Sq(&S);

        while(s[i]){
                switch(s[i]){
                        case '(':
                        case '[':
                        case '{':
                                Push(&S, s[i]);
                                break;

                        case ')':
                        case ']':
                        case '}':
                                if(StackEmpty(S))
                                        return 0;

                                Pop_Sq(&S,  &e);
                                if(!Matching(e, s[i]))
                                        return 0;
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
        char *s = "1+2)*3/{2/[(4-5)*3]-5*(8-7)}";

        printf("判断表达式 %s 括号是否匹配...\n", s);

        if(Algo_3_19(s))
                printf("表达式括号匹配!\n");
        else
                printf("表达式括号不匹配!\n");

        printf("\n");

        return 0;
}

