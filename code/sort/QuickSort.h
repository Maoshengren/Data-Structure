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

//一趟快速排序
int partition(SqList *L, int low, int high){
    L->r[0] = L->r[low];
    int pivotkey = L->r[low].key;
    while(low < high){
        while(low < high && L->r[high].key >= pivotkey)
            --high;
        L->r[low] = L->r[high];
        while(low < high && L->r[low].key <= pivotkey)
            ++low;
        L->r[high] = L->r[low];
    }
    L->r[low] = L->r[0];
    return low;
}

void QuickSort(SqList *L, int low, int high){
    int pivokey = partition(L, low, high);
    QuickSort(L, pivokey + 1, high);
    QuickSort(L, low, pivokey - 1);
}
