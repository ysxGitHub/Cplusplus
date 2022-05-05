#include<iostream>
#include<algorithm>
using namespace std;

// 该算法稳定
// T(N, I) = O(N+I),  其中I为逆序对的个数
// 较快的排序是一次同时消除多个逆序对
template<class T>
void Insertion_Sort(T A[], int n){
    for(int p=1; p<n; p++){
        int temp = A[p]; // 抽一张牌
        int i=p;
        for(i; i>0&&A[i-1]>temp; i--){ //手中还有牌并且当前的牌大于抽到的牌
            A[i] = A[i-1]; // 交换两张牌
        }
        A[i] = temp; // 插入该张牌
    }
}

template<class T>
void Printc(T A[], int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<"  ";
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int A[10] = {1,4,2,3,0,6,9,8,5,7};
    Insertion_Sort<int>(A, 10);
    Printc(A, 10);

    return 0;
}

