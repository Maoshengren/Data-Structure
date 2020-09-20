#include<stdlib.h>
#include"SqStack.h"
#define SIZE 20

//检验括号匹配函数
char BracketCorrespondency(char a[]){
    SqStack S;
    InitStack(&S);          //初始化
    SElemType x;
    int i = 0;              //记录元素位置
    while(a[i]){
        switch (a[i])
        {
        case '(':
            Push(&S,a[i]);
            break;
        case '[':
            Push(&S,a[i]);
            break;
        case ')':
            x = GetTop(S,x);
            if(x == '(')
                Pop(&S,x);
            else
                return ERROR;
            break;
        case ']':
            x = GetTop(S,x);
            if(x == '[')
                Pop(&S,x);
            else 
                return ERROR;
            break;
        default:
            break;
        }
        i++;
    }
    if(S.stacksize != 0)
        return -1;
    return 1;
}

//接收括号函数
void GetBracket(char a[]){
    char i;
    int j = 0;
    printf("请输入括号以匹配：(回车即结束)\n");
    while((i = getchar()) != '\n'){         //当输入字符为回车时结束
        a[j] = i;
        j ++;
    }
    a[j] = '\0';
}

int main(){
    char a[SIZE];
    GetBracket(a);          //初始化字符数组
    if(BracketCorrespondency(a))    //判断括号的匹配
        printf("成功匹配！\n");
    else
        printf("匹配失败！\n");
    return 0;
}