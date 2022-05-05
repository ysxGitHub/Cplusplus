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
void Merge(T A[], T Temp_A[], int L, int R, int RightEnd){
    int LeftEnd = R-1;
    int Tmp = L;
    int Nums = RightEnd - L + 1;
    while (L <= LeftEnd && R<=RightEnd){
        if(A[L]<=A[R]){
            Temp_A[Tmp++] = A[L++];
        }
        else{
            Temp_A[Tmp++] = A[R++];
        }
        
    }
    while (L<=LeftEnd){
        Temp_A[Tmp++] = A[L++];
    }

    while (R<=RightEnd){
        Temp_A[Tmp++] = A[R++];
    }

    for(int i=0; i<Nums; i++, RightEnd--){
        A[RightEnd] = Temp_A[RightEnd];
    }
    
}

template<class T>
void Msort(T A[], T Temp_A[], int L, int RightEnd){
    if(L<RightEnd){
        int Center = (L+RightEnd)/2;
        Msort(A, Temp_A, L, Center);
        Msort(A, Temp_A, Center+1, RightEnd);
        Merge<T>(A, Temp_A, L, Center+1, RightEnd);
    }
}

// 归并排序 稳定 在外排序有用
template<class T>
void Merge_sort(T A[], int N){
    // T Temp_A[N] = {0};
    T* Temp_A = new T[N];
    // 先定义Temp_A数组，为了防止再递归中多次声明该数组
    Msort(A, Temp_A, 0, N-1);
    delete[] Temp_A;
}

int main(int argc, char const *argv[])
{
    int A[10] = {1,4,2,3,0,6,9,8,5,7};
    Merge_sort(A, 10);
    Printc(A, 10);
    return 0;
}
