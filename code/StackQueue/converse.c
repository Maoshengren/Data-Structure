
#include<stdio.h>
#include"SqStack.h"
void converse(){
    SqStack S;
    InitStack(&S);
    int N;
    SElemType e;
    scanf("%d",&N);
    while(N){
        if(Push(&S,N%8));
            N = N/8;
    }
    while(!StackEmpty(S)){
        //注意数字类型需要正确的声明
        printf("%d",Pop(&S,e));
    }
}

int main(){
    converse();
    return 0;
}