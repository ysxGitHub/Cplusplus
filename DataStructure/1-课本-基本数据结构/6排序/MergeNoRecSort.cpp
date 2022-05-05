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

    // for(int i=0; i<Nums; i++, RightEnd--){
    //     A[RightEnd] = Temp_A[RightEnd];
    // }
    
}

template<class T>
void Merge_pass(T A[], T Temp_A[], int N, int length){
    // length: 为当前子序列的长度
    int i=0;
    for(i; i<=N-2*length; i+=2*length){
        Merge(A, Temp_A, i, i+length, i+2*length-1);
    }
    if(i+length<N){
        // 归并最后2个子列
        Merge(A, Temp_A, i, i+length, N-1);
    }
    else{
        // 最后只剩1个之列
        for(int j=i; j<N; j++){
            Temp_A[j] = A[j];
        }
    }

}


template<class T>
void Merge_sort(T A[], int N){
    T* Temp_A = new T[N];
    int length = 1;
    while (length<N){
        Merge_pass(A, Temp_A, N, length);
        length *= 2;
        Merge_pass(Temp_A, A, N, length);
        length *= 2;
    }
    delete[] Temp_A;
}

int main(int argc, char const *argv[])
{
    int A[10] = {1,4,2,3,0,6,9,8,5,7};
    Merge_sort(A, 10);
    Printc(A, 10);
    return 0;
}
