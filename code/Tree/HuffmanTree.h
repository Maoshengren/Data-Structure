#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Status int
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define MAX 65535
//-----赫夫曼树和赫夫曼编码的存储表示- - -- -
typedef struct {
    unsigned int weight;
    unsigned int parent, lchild, rchild;
}HTNode,*HuffmanTree;
//动态分配数组存储赫夫曼树
typedef char* *HuffmanCode;//动态分配数组存储赫夫曼编码表

//求赫夫曼编码
Status HuffmanCoding(HuffmanTree *HT, HuffmanCode *HC, int *w, int n){
    //w存放n个字符的权值(均>0),构造赫夫曼树HT,并求出赫夫曼编码HC。
    int m,s1,s2,i,c,start,f;
    char *cd;
    HuffmanTree p;      //初始化一个哈夫曼树
    if(n < 1)
        return 0;
    m = 2 * n - 1;
    *HT = (HuffmanTree)malloc((m + 1) * sizeof(HTNode));    //0号单元不使用
    for(p = *HT,i = 1; i <=n; i++){     //叶子结点初始化
        p[i].weight = w[i-1];
        p[i].parent = 0;
        p[i].lchild = 0;
        p[i].rchild = 0;
    }
    for(;i <= m; i++){          //非叶子结点初始化
        p[i].weight = 0;
        p[i].parent = 0;
        p[i].lchild = 0;
        p[i].rchild = 0;
    }
    for(i = n + 1; i <= m; i++){
        //选择两个parent域为0且weight值最小的结点，并返回
        Select(*HT, i - 1, &s1, &s2);
        (*HT)[s1].parent = i;
        (*HT)[s2].parent = i;
        (*HT)[i].lchild = s1;
        (*HT)[i].rchild = s2;
        (*HT)[i].weight = (*HT)[s1].weight + (*HT)[s2].weight;
    }//赫夫曼树建立完毕

    //从叶子结点到根，逆向求每个叶子结点的赫夫曼编码
    *HC = (HuffmanCode)malloc(sizeof(char*)*(n+1));     //分配n个编码的头指针
    cd = (char*)malloc(n*sizeof(char));                 //分配求当前编码的工作空间
    cd[n-1] = '\0';         //从右向左存放编码，首先存放结束字符
    for(i = 1; i <= n; i++){
        start = n - 1;
        for(c = i,f = (*HT)[i].parent; f != 0; c = f, f = (*HT)[f].parent)  //从叶子到根求编码
            if((*HT)[f].lchild == c)
                cd[start --] = '0';         //左分支标记为0
            else
                cd[-- start] = '1';         //右分支标记为1
        (*HC)[i] = (char*)malloc(sizeof(char)*(n - start));     //为第i个编码分配空间
        strcpy((*HC)[i],&cd[start]);
        free(cd);
    }
}

//HT中选择parent为0且weight最小的两个节点，序号分别为s1，s2
void Select(HuffmanTree HT, int i, int *s1, int *s2){
    int j;
    int min;
    min = MAX;
    for(j = 1; j <= i; j++){
        if(HT[j].parent == 0 && HT[j].weight <= min){
            *s1 = j;
            min = HT[j].weight;
        }
    }
    HT[*s1].parent = *s1;
    min = MAX;
    for(j = 1; j <= i; j++){
        if(HT[j].parent == 0 && HT[j].weight <= min){
            *s2 = j;
            min = HT[j].weight;
        }
    }
    HT[*s2].parent = *s2;
}