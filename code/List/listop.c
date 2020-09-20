#include<stdio.h>
#include<stdlib.h>
#define ERROR 0
#define OK 1 
#define OVERFLOW -2
#define ElemType int 
#define Status int 
typedef struct LNode{		//���������ݴ洢��ʽ 
	int data;
	struct LNode *next;
}LNode,*LinkList;

//��ʼ��һ���������� 
void InitList(LinkList L){
	L = (LinkList)malloc(sizeof(LNode));
	if(L == NULL)
		exit(OVERFLOW);
	L->next = NULL;
} 

//����Ѿ����ڵ����Ա�
void ClearList(LinkList L){
	LinkList p;
	while(L->next){
		p = L->next;
		L->next = p->next;
		free(p);
	}
} 

//�������Ա�
void DestroyList(LinkList L){
	ClearList(L);
	free(L);
	L = NULL;
} 

//�жϱ��Ƿ�Ϊ��
Status IsEmpty(LinkList L){
    if(L->next == NULL)
    	return OK;
    else
   		return ERROR;
} 

//�������Ա�Ԫ�صĸ���
Status ListLenth(LinkList L){
	int i = 0;
	if(L == NULL)
		return ERROR;
	LinkList p;
	p = L;
	while(p->next){
		p = p->next;
		i++;
	}
	return i;
} 

//
//ȡ�������еĵ�i��Ԫ�أ��������Ԫ��e�� 
Status GetElem(LinkList L,int i, ElemType *e){
	int j = 0;
	LNode *p;
	p = L->next;
	while(p && j < i-1){
		p = p->next;
		++j;
	}
	if(!p||j > i-1)		// iС��1���ߴ��ڱ�����1
		return ERROR;
	*e = p->data;
	return OK;
}

//����Ԫ��e����i��λ�� 
Status ListInsert(LNode* L,int i,ElemType e){
	int j = 0;
	LNode *p,*s;
	p = L;
	while( p && j < i-1 ){
		p = p->next;
		j++;
	} 
	if(!p||j > i-1)		// iС��1���ߴ��ڱ�����1
		return ERROR;
	s = (LNode*)malloc(sizeof(LNode));	//����ռ� 
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

//ɾ�������е�i��Ԫ�أ�����������e�� 
Status ListDelete(LNode* L, int i, ElemType *e){
	int j = 0;
	LNode *p,*q;
	p = L;
	while(p && j < i-1){
		p = p->next;
		j++;
	} 
	if(!p || j > i-1)
		return ERROR;
	q = p->next,p->next = q->next;		//ɾ����i�����	
	*e = q->data;		//e��ŵ�i��Ԫ�ص����� 
	free(q);
	return OK;
}

//����L�е�1����e�����ϵcompare()������Ԫ�ص�λ��
//������������Ԫ�ز�����,�򷵻�ֵΪ0
Status LocateElem(LinkList L, ElemType e){
    int i = 1; 
    LinkList p;
    p = L->next;
  	while(p && p->data != e){
    	p=p->next;
    	i++; 
	}
	if(p != NULL )
 		return i;
	else
 		return ERROR; 
}

void operation(){
	printf("��ѡ��������еĲ���:\n");
	printf("1------>��ʼ�����Ա�\n");
	printf("2------>������Ա�\n"); 
	printf("3------>�������Ա�\n");
	printf("4------>�жϱ��Ƿ�Ϊ��\n");
	printf("5------>����Ԫ�ظ���\n");
	printf("6------>ȡ�������еĵ�i��Ԫ��\n");
	printf("7------>����Ԫ��e����i��λ��\n");
	printf("8------>ɾ�������е�i��Ԫ��\n");
	printf("9------>����L�е�1����e�����ϵ��Ԫ��\n");
	printf("Ctrl+Z�˳�\n");
}

int main(){
	int i,j,k;
	LinkList L;
	operation();
	while(scanf("%d",&i)!=EOF){ 
		if(i == 1){
			InitList(L);
			printf("OK��");
		}			
		if(i == 2){
			ClearList(L);
			printf("OK");
		}
		if(i == 3){
			DestroyList(L);
			printf("OK");
		} 
		if(i == 4){
			j = IsEmpty(L);
			if(j)
				printf("�ǿյģ�");
			else
				printf("���ǿյģ�");
		}
		if(i == 5){
			printf("����Ϊ��%d",ListLenth(L));
		} 
		if(i == 6){
			scanf("%d",&j);
			if(GetElem(L,j,&k))
				printf("Ԫ�صõ��ˣ�%d",k);
			else
				printf("�������");
		}
		if(i == 7){
			printf("������λ��j�Ͳ���Ԫ��k:");
			scanf("%d%d",&j,&k);
			if(ListInsert(L,j,k))
				printf("�ɹ��ˣ�");
			else
				printf("��ô���£�"); 	
		}
		if(i == 8){
			printf("������ɾ��Ԫ�ص�λ��j:");
			scanf("%d",&j) ;
			if(ListDelete(L,j,&k))
				printf("��ɾ��Ԫ�أ�%d",k);
			else
				printf("��Ŷ��ʧ����!");
		}
		if(i == 9)	{
			printf("������Ԫ��k��");
			scanf("%d",&k);
			j = LocateElem(L,k);
			if(j)
				printf("e��λ�ã�%d",j);
			else
				printf("ʧ������");
		}
		operation();
	}
	return 0;
}



