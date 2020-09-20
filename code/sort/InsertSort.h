#define MAXSIZE 20			//一个用作示例的小顺序表的最大长度
typedef int KeyType;		//定义关键字类型为整数类型.
typedef struct {
    KeyType key;			//关键字项
    //InfoType other info;	//其他数据项
}RedType ;//记录类型
typedef struct {
    RedType r[MAXSIZE + 1];	// r[0]闲置或用作哨兵单元
    int length;				//顺序表长度
}SqList;//顺序表类型

//插入排序，每次将待插入的数字与前一个数字比较
//若比前一个数小，那么插入到前面的序列的合适位置
void InsertSort(SqList *L){
    int i;
    for(i = 2; i <= L->length; i++){
        if(L->r[i].key < L->r[i-1].key){
            L->r[0] = L->r[i];
            L->r[i] = L->r[i-1];
            int j;
            for(j = i-2; L->r[0].key < L->r[j].key; j--)
                L->r[j+1] = L->r[j];
            L->r[j+1] = L->r[0];
        }
    }
}

//折半查找，插入排序
void BInsertSort(SqList *L){
    int i;
    for(i = 2; i <= L->length; i++){
        if(L->r[i].key < L->r[i-1].key){
            L->r[0] = L->r[i];
            int low = 1, high = i - 1;
            while(low <= high){
                int m = (low + high)/2;
                if(L->r[0].key < L->r[m].key)
                    high = m - 1;
                else
                    low = m + 1;
            }
            int j;
            for(j = i - 1; j < high; j--)
                L->r[j+1] = L->r[j];
            L->r[high+1] = L->r[0];
        }
    }
}

//表插入排序
#define SIZE 100
#define RcdType int

typedef struct{
    RcdType rc;     //记录项
    int next;       //指针项
}SLNode;

typedef struct{
    SLNode r[SIZE];
    int length;
}SLinkListType;     //静态链表类型

