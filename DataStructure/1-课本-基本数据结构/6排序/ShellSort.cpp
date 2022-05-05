#include<iostream>
#include<algorithm>
using namespace std;

// 希尔排序
// 希尔排序中的D是需要调整的
template<class T>
void Shell_Sort(T A[], int n){
    for(int D=n/2; D>0; D/=2){
        for(int p=D; p<n; p++){
            int temp = A[p]; // 抽一张牌
            int i=p;
            for(i; i>=D && A[i-D]>temp; i-=D){ //手中还有牌并且当前的牌大于抽到的牌
                A[i] = A[i-D]; // 交换两张牌
            }
            A[i] = temp; // 插入该张牌
        }
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
    Shell_Sort<int>(A, 10);
    Printc(A, 10);
    return 0;
}
