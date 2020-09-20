#include<stdio.h>
#include<stdlib.h>
#define STACK_INIT_SIZE 100	//存储空间初始分配量
#define STACKINCREMENT 10		//存储空间分配增量
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define SElemType BiTree
#define Status int 
typedef struct{
    SElemType  *base;
    SElemType  *top;
    int  stacksize;				//栈当前可使用的最大容量
}SqStack;

//初始化一个栈
Status InitStack(SqStack *S){
	S->base = (SElemType*)malloc(sizeof(SElemType)*STACK_INIT_SIZE);
    if(!S->base)
        exit(OVERFLOW);
    S->top = S->base;
    S->stacksize = STACK_INIT_SIZE;
    return OK;
}

//取栈顶元素
Status GetTop(SqStack S, SElemType *e){
    if(S.top == S.base)
        return ERROR;
    *e = *(S.top - 1);
    return OK;
}

//插入元素
Status Push(SqStack *S, SElemType e){
    if((S->top - S->base) > STACK_INIT_SIZE) {       //栈满，追加空间
        S->base = (SElemType*)realloc(S->base,(S->stacksize + STACKINCREMENT)*sizeof(SElemType));
        if(!S->base)
            exit(OVERFLOW);
        S->top = S->base + S->stacksize;
        S->stacksize += STACKINCREMENT;
    }
    *S->top ++ = e;
    return OK;
}

//删除元素
Status Pop(SqStack *S, SElemType *e){
    if(S->top == S->base)
        return ERROR;
    *e = *--S->top;
    return OK;
}

//清空栈
Status ClearStack(SqStack *S){
    /*if(S.top == S.base)
        return ERROR;
    SElemType *p;
    while(S.top != S.base){
        p = S.top;
        S.top--;
        free(p);
    }*/
    S->top = S->base;
    return OK;
}

//删除栈
Status DeleteStack(SqStack *S){
    int len = S->stacksize;
    for(int i = 0; i < len; i++){
        free(S->base);
        S->base ++;
    }
    S->base = S->top = NULL;
    S->stacksize = 0;
    return OK;
}

//若栈S为空栈,则返回TRUE,否则FALSE
Status StackEmpty(SqStack S){
    if(S.top == S.base)
        return OK;
    else 
        return ERROR;
}
 
//返回S的元素个数，即栈的长度
int StackLenth(SqStack S){
    if(S.base == S.top)
        return ERROR;
    return (S.top - S.base);
}

