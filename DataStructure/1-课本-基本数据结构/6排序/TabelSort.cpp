#include<iostream>
using namespace std;

template<class T>
void Printc(T A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl;
}

/*
    当待排数组中的元素不是简简单单的整数，而是复杂的结构体，
    那么移动元素所花费的时间就不能忽略不计了，
    这时候我们要减少元素之间移动的次数了。
    表排序就是这么一个排序，在表排序的过程中，
    实际上是不需要移动元数的，我们要移动的是指向这些元素的指针。
*/ 

/* 表排序 */
template<class T>
void Table_Sort(T *A, int Size)
{
    int *Table = NULL;
    T TempA;
    int i = 0, j = 0, Temp = 0;

    /* 申请Table空间 */
    Table = new int[Size];

    /* 初始化Table */
    for (i = 0; i < Size; i++)
    {
        Table[i] = i;
    }

    /* 给Table排序（任何排序方法都可以）这里使用的是插入排序 */
    for (i = 1; i < Size; i++)
    {
        // 抽一张牌
        Temp = Table[i];
        // 比较手中的牌与抽到的牌
        for (j = i; j > 0 && A[Temp] < A[Table[j-1]]; j--)
        {
            // 手中的牌位置移动
            Table[j] = Table[j - 1];
        }
        // 将抽到的牌放到手中
        Table[j] = Temp;
    }

    /* 给数组排序 */
    for (i = 0; i < Size; i++)
    {
        // 判断环中元素个数，不等于1时
        if (i != Table[i])
        {
            // 取出环首元素
            TempA = A[i];
            // 判断环是否结尾
            for (j = i; Table[Table[j]] != Table[j]; j = Temp)
            {
                // 将下一个table指向的位置放入当前位置
                A[j] = A[Table[j]];
                // 保存下一个位置的index
                Temp = Table[j];
                // 将下一个位置地index替换为当前地
                Table[j] = j;
            }
            A[j] = TempA;
        }
    }

    /* 释放Table空间 */
    delete[] Table;
}


int main(int argc, char const *argv[])
{
    int A[] = {1,4,2,3,0,6,9,8,5,7,11,10,17,19,18,14,12,13,16,15};
    int N = sizeof(A)/sizeof(int);
    Table_Sort(A, N);
    Printc(A, N);
    return 0;
}
