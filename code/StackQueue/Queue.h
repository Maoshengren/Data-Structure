#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define QElemType int
#define Status int

typedef struct QNode {
    QElemType data;
    struct QNode *next;
}QNode, *QueuePtr;

typedef struct {
    QueuePtr front; //队头指针
    QueuePtr rear;  //队尾指针
    int count;      //储存元素个数
}LinkQueue;

//初始化队列
Status InitQueue(LinkQueue *Q){
    Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
    if( !Q->front)
        exit(OVERFLOW);
    Q->front = NULL;
    Q->count = 0;
    return OK;
}

//清空队列
Status ClearQueue(LinkQueue *Q){
    QueuePtr p;
    p = Q->front->next;
    while(Q->front != Q->rear){
        Q->front = p->next;
        free(p);
        p = Q->front;
    }
    Q->front = Q->rear = NULL;
    Q->count = 0;
    return OK;
}

//判断队列是否为空
Status QueueEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return OK;
    else
        return ERROR;
}

//返回队列长度
Status QueueLenth(LinkQueue Q){
    return Q.count;
}

//销毁队列
Status DestroyQueue(LinkQueue *Q){
    while(Q->front){
        Q->rear = Q->front->next;
        free(Q->front);
        Q->front = Q->rear;
    }
    return OK;
}

//插入元素
Status EnQueue(LinkQueue *Q, QElemType e){
    QueuePtr P;
    P = (QueuePtr)malloc(sizeof(QNode));
    if(!P)
        exit(OVERFLOW);
    P->data = e;
    P->next = NULL;
    Q->rear->next = P;
    Q->rear = P;
    Q->count ++;
    return OK;
}

//删除元素
Status DeQueue(LinkQueue *Q, QElemType e){
    if(Q->front == Q->rear)
        return ERROR;
    e = Q->front->data;
    QueuePtr P;
    P = Q->front->next;
    Q->front->next = P->next;
    if(Q->rear == P)
        Q->rear = Q->front;
    free(P);
    Q->count --;
    return e;
}

//取队头元素
Status GetHead(LinkQueue Q, QElemType *e){
    if(Q.rear == Q.front)
        return ERROR;
    *e = Q.front->next->data;
}