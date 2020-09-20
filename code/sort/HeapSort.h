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

typedef SqList HeapType;

void HeapAdjust(HeapType *H, int s, int m){
    RedType rc = H->r[s];
    int j;
    for(j = 2*s; j <= m; j*=2){
        if(j < m && H->r[j].key < H->r[j+1].key)
            j++;
        if(!(rc.key < H->r[j].key))
            break;
        H->r[s]  = H->r[j];
        s = j;
    }
    H->r[s] = rc;
}

void HeapSort(HeapType *H){
    int i;
    for(i = H->length/2; i > 0; i--)
        HeapAdjust(H, i, H->length);
    for(i = H->length; i > 1; i--){
        RedType temp = H->r[1];
        H->r[1] = H->r[i];
        H->r[i] = H->r[1];
        HeapAdjust(H, 1, i-1);
    }
}
