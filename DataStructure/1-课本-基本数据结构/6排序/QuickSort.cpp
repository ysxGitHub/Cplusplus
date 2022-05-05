#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int cutoff=3;

// 
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


// 寻找主元
template<class T>
T Median3(T A[], int left, int right){
    int center = (left+right)/2;
    if(A[left]>A[center]){
        swap(A[left], A[center]);
    }
    if(A[left]>A[right]){
        swap(A[left], A[right]);
    }
    if(A[center]>A[right]){
        swap(A[center], A[right]);
    }
    // 将主元换到A[right-1]
    swap(A[center], A[right-1]);

    return A[right-1];
}

template<class T>
void Quicksort(T A[], int left, int right){
    if(cutoff<=right-left){
        T pivot = Median3(A, left, right);
        int i = left;
        int j = right-1;
        for(;;){
            while (A[++i]<pivot){};
            while (A[--j]>pivot){};
            // 左指针小于右指针时，交换两边元素
            if(i<j){
                swap(A[i], A[j]);
            }
            // 子集划分结束
            else{
                break;
            }
        }
        // 将主元换到A[i]上
        swap(A[i], A[right-1]);
        Quicksort(A, left, i-1);
        Quicksort(A, i+1, right);
    }
    // 子序列短于cutoff时，调用插入排序
    else{
        Insertion_Sort<T>(A+left, right-left+1);
    }
}

template<class T>
void Quick_Sort(T A[], int N){
    Quicksort(A, 0, N-1);
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
    int A[] = {1,4,2,3,0,6,9,8,5,7,11,10,17,19,18,14,12,13,16,15};
    int N = sizeof(A)/sizeof(int);
    Quick_Sort(A, N);
    Printc(A, N);
    // srand((int)time(0));
    // cout<<rand()<<endl;

    return 0;
}


