#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define Status int

typedef struct{
	char *ch;
    int lenth;
}HString;

//串赋值,生成一个其值等于chars的串T
Status StrAssign (HString *T, char *s){
    int i,j;
    if(T->ch)
        free(T->ch);
    i = strlen(s);
    if(!i){
        T->ch = NULL;
        T->lenth = 0;
    }
    else{
        if(!(T->ch = (char*)malloc(sizeof(char)*i)))
            exit(OVERFLOW);
        for(j = 0; j < i; j++)
            T->ch[j] = s[j];
        T->lenth = i;
    }
    return OK;
}
//判断串空
Status StrEmpty(HString S){
    if(S.ch == NULL && S.lenth == 0)
        return OK;
    else
        return ERROR;
}

//复值串,将T的值赋值给S
Status StrCopy(HString *S, HString T){
    int i;
    if(S->ch)
        free(S->ch);
    S->ch = (char*)malloc(sizeof(char)* strlen(T.ch));
    if(!S->ch)
        exit(OVERFLOW);
    for(i = 0; i < strlen(T.ch); i++)
        S->ch[i] = T.ch[i];
    S->lenth = T.lenth;
    return OK;
}

//串比较
//S > T,则返回值 > 0;若S = T,则返回值 = 0;若S < T,则返回值 < 0
Status StrCompare(HString S, HString T){
    int i;
    for(i = 0; i < S.lenth && i < T.lenth; i++)
        if(S.ch[i] != T.ch[i])
            return S.ch[i] - T.ch[i];
    return S.lenth - T.lenth;
}

//求串长
Status StrLength (HString S){
    return S.lenth;
}   

//清空串，释放传递空间
Status StrClean(HString *S){
    if(S->ch){
        free(S->ch);
        S->ch = NULL;
    }
    S->lenth = 0;
    return OK;
}

//串连接
Status StrConcat(HString *T, HString S1, HString S2){
    if (T->ch) 
        free(T->ch) ;       //释放旧空间
    if (!(T->ch = (char *) malloc((S1.lenth + S2.lenth) * sizeof(char))))
    	exit (OVERFLOW);
    int i;
    for(i = 0; i < S1.lenth; i++)
        T->ch[i] = S1.ch[i];
    for(i = 0; i < S2.lenth; i++)
        T->ch[i + S1.lenth - 1] = S2.ch[i];
    return OK;
}   

//返回子串
Status SubString(HString *Sub, HString S, int pos, int len){
    //用Sub返回串S的第pos个字符起长度为len的子串。
    //其中,1≤pos≤SStrLength(S)且 0≤len≤StrLength(S)- pos+ 1.
    if (pos < 1 || pos > S.lenth || len < 0 || len > S.lenth - pos + 1)
    	return ERROR;
    if(Sub->ch)
        free(Sub->ch);
    
    int i;
    if (!len) {
        Sub->ch = NULL; 
        Sub->lenth = 0; 
    }//空子串
    else{
        if(!(Sub->ch = (char*)malloc(len * sizeof(char))))
            exit(OVERFLOW);
        for(i = 0; i < len - 1; i++)
            Sub->ch[i] = S.ch[i + pos - 1];
    }
        
    return OK;
}

