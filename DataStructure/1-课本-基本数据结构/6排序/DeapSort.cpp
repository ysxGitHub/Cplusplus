#include<iostream>
#include<algorithm>
using namespace std;


template<class T>
void Printc(T A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl;
}


template<class T> 
void PercDown(T A[], int p, int N ){ 
    // 改编自上一章学习的堆的PercDown(MaxHeap H, int p) 
    // 将N个元素的数组中以A[p]为根的子堆调整为最大堆
    int Parent, Child;

    T X = A[p]; // 取出根结点存放的值 
    for(Parent = p; (Parent * 2 + 1) < N; Parent = Child){
        Child = Parent * 2 + 1;
        if((Child != N-1) && (A[Child] < A[Child + 1])){
            Child++;  // Child指向左右子结点的较大者
        }
        if(X >= A[Child]){ 
            // 找到了合适位置
            break; 
        }
        else{
            // 下滤X 
            A[Parent] = A[Child];
        }   
    }
    A[Parent] = X;
}


// 
template<class T> 
void Heap_Sort(T A[], int N){
    int i;
    /* 建立最大堆 *，已知数组从下标0开始的，那么最后一个有子节点的数组元素下标为N/2-1 */
    for ( i=N/2-1; i>=0; i--){
        PercDown<T>(A , i, N);
    }
    // Printc(A, 10);
    for (i=N-1; i>0; i--){
        /* 删除最大堆顶 */
        swap(A[0], A[i]); 
        PercDown<T>(A, 0, i);
    }
}



int main(int argc, char const *argv[])
{
    int A[10] = {1,4,2,3,0,6,9,8,5,7};
    Heap_Sort(A, 10);
    Printc(A, 10);
    return 0;
}
