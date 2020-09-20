#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define Status int
#define MAXSTRLEN 250
typedef unsigned char SString[MAXSTRLEN + 1];

//串赋值
Status StrAssign (SString T, char *s){
    int i;
    if(strlen(s) > MAXSTRLEN)
        return ERROR;
    T[0] = strlen(s);
    for(i = 1; i < T[0]; i++)
        T[i] = *(s + i -1);
    return OK;
}

//判断串空
Status StrEmpty(SString S){
    if(S[0] == 0)
        return OK;
    return ERROR;
}

//串比较
//S > T,则返回值 > 0;若S = T,则返回值 = 0;若S < T,则返回值 < 0
Status StrCompare(SString S, SString T){
    int i;
    for(i = 0; i < S[0] && i < T[0]; i++)
        if(S[i] != T[i])
            return S[i] - T[i];
    return S[0] - T[0];
}

//求串长
Status StrLength (SString S){
    return S[0];
}

//复值串,将T的值赋值给S
Status StrCopy(SString S, SString T){
    int i;
    for(i = 0; i < T[0]; i++)
        S[0] = T[0];
    return OK;
}
//串连接
Status StrConcat( SString T, SString S1, SString S2) {
    int i;
    if(S1[0] + S2[0] <= MAXSTRLEN){
        for(i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for(i = 1; i <= S2[0]; i++)
            T[i + S1[0]] = S2[i];
        return OK;
    }
    else if(S1[0] > MAXSTRLEN){
        for(i = 1; i <= MAXSTRLEN; i++)
            T[i] = S1[i];
        T[0] = MAXSTRLEN;
    }
    else{
        for(i = 1; i <= S1[0]; i++)
            T[i] = S1[i];
        for(i = 1; i <= MAXSTRLEN - S1[0]; i++)
            T[i + S1[0]] = S2[i];
    }
}

//求子串
//用Sub返回串S的第pos个字符起长度为len的子串
Status SubString(SString Sub, SString S, int pos, int len){
    if(len < 0 || len > S[0] - pos + 1 || pos < 1 || pos > S[0])
        return ERROR;
    int i,j = 0;
    Sub[0] = len;
    for(i = pos,j = 1; i < len; i++, j++)
        Sub[j] = S[i];
    return OK;
}

//在串S的第pos个字符之前插入串T
Status StrInsert(SString S, int pos, SString T){
    if(pos > MAXSTRLEN + 1 || pos < 1 )
        return ERROR;
    int i;
    if(pos + T[0] <= MAXSTRLEN){
        for(i = pos + T[0]; i >= pos; i-- )     //挪出T串所需空间
            S[i] = S[i - pos];
        for(i = 1; i <= T[0]; i++)
            S[i + pos - 1] = T[i];
        S[0] += T[0];
        return OK;
    }
    else{
        for(i = 1;i < T[0]; i++)
            S[i + pos - 1] = T[i];
        S[0] = MAXSTRLEN;
        return ERROR;
    }
}

//从串S中删除第pos个字符起长度为len的子串
Status StrDelete(SString S, int pos, int len){
    if(pos > MAXSTRLEN + 1 || pos < 1 || pos + len > MAXSTRLEN || len < 0)
        return ERROR;
    int i;
    for(i = pos; i < MAXSTRLEN - len; i++)
        S[i] = S[i + len];
    S[0] -= len;
    return OK;
}

//若主串S中存在和串T值相同的子串，则返回它在主串S中第pos个字符之后第一次出现的位置
//否则函数值为0
Status StrIndex(SString S, SString T, int pos){
    
}

//用V替换主串S中出现的所有与T相等的不重叠的子串
Status StrReplace(SString S, SString T, SString V){

}

