#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define QElemType int
#define Status int
#define MAXQSIZE 100  		//最大队列长度

typedef struct {
	QElemType* base;		//初始化的动态分配存储空间.
    int front;				//头指针,若队列不空,指向队列头元素
    int rear ;				//尾指针,若队列不空,指向队列尾元素的下一个位置
}SqQueue;

//初始化队列
Status InitQueue(SqQueue *Q){
    Q->base = (QElemType*)malloc(sizeof(QElemType)* MAXQSIZE);
    if(!Q->base)
        exit(OVERFLOW);
    Q->front = Q->rear = 0;
    return OK;
} 

//返回元素个数
Status QueueLength(SqQueue Q) {
    return ((Q.rear - Q.base + MAXQSIZE) % MAXQSIZE);
}

//元素进队列
Status EnQueue(SqQueue *Q, QElemType e){
    if((Q->rear + 1)%MAXQSIZE == Q->front)
        return ERROR;
    Q->base[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAXQSIZE;
    return OK;
}

//元素出队列
Status DeQueue(SqQueue *Q, QElemType *e){
    //若队列不空,则删除Q的队头元素,用e返回其值,并返回OK;
    //否则返回ERROR
    if (Q->front == Q->rear) 
        return ERROR;
    *e = Q->base[Q->front];
    Q->front = (Q->front + 1) % MAXQSIZE; 
    return OK;
}