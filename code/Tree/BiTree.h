#include<stdio.h>
#include<stdlib.h>
#include"SqStack.h"
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define Status int
#define TElemType char
#define INITSIZE 100

typedef struct BiTNode{
    TElemType data;
    struct BiTNode * lchild, *rchild; // 左右孩子指针
}BiTNode, *BiTree;

//先序遍历递归算法
void PreOrderTraversal(BiTree BT){
    if(BT){
        printf("%d",BT->data);
        PreOrderTraversal(BT->lchild);
        PreOrderTraversal(BT->rchild);
    }
}

//先序遍历所有叶子结点
void PreOderBiTree(BiTree BT){
    if(BT){
        if(BT->lchild ==NULL && BT->rchild == NULL)
            printf("%d",BT->data);
        PreOderBiTree(BT->lchild);
        PreOderBiTree(BT->rchild);
    }
}

//统计叶子结点数
Status CaculateLeafCount(BiTree BT){
    int count = 0;
    if(BT){
        if(BT->lchild ==NULL && BT->rchild == NULL)
            count ++;
        CaculateLeafCount(BT->lchild);
        CaculateLeafCount(BT->rchild);
    }
    return count;
}

//求二叉树高度
Status DepthByPostTree(BiTree BT){
    int LHeight,RHeight,Max;
    if(BT){
        LHeight = DepthByPostTree(BT->lchild);
        RHeight = DepthByPostTree(BT->rchild);
        if(LHeight > RHeight)
            Max = LHeight;
        else
            Max = RHeight;
        return (Max + 1);
    }
    else
        return 0;
}

//非递归先序遍历
void PreoderByStack(BiTree BT){
    SqStack S;
    InitStack(&S);
    BiTree p;
    p = BT;
    while(!StackEmpty(S) && p != NULL){
        while (p != NULL){
            printf("%d",p->data);
            Push(&S, p);
            p = p->lchild;
        }
        if(!StackEmpty(S)){
            Pop(&S, p);
            p = p->rchild;
        }
    }
    DeleteStack(&S);
}

//非递归后序遍历
void PostOrderByStack(BiTree BT){
    BiTree p,q;
    BiTree *s;
    int top = 0;
    q = NULL;
    p = BT;
    s = (BiTree*)malloc(sizeof(BiTree)*INITSIZE);
    while (p != NULL || top != 0)
    {
        while(p != NULL){
            top ++;
            s[top] = p;
            p = p->lchild;
        }   //遍历左子树
        if(top > 0){
            p = s[top];
            if((p->rchild == NULL) || (p->rchild == q)){    //无右孩子，或已经遍历过
                printf("%d",p->data);   //访问根结点
                q = p;
                top --;
                p = NULL;
            }
            else
                p = p->rchild;
        }
    }
    free(s);
}

//先序创建二叉树
void PreOrderCreateBitree(BiTree BT){
    char ch;
    ch = getchar();
    if(ch == ' ')
        BT = NULL;
    else
    {
        if(!( BT = (BiTree)malloc(sizeof(BiTNode))))
            exit(OVERFLOW);
        BT->data = ch;
        PreOrderCreateBitree(BT->lchild);
        PreOrderCreateBitree(BT->rchild);
    }
}

//