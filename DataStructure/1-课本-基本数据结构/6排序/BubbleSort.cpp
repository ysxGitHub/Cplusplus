#include<iostream>
#include<algorithm>
using namespace std;

// 该算法稳定
template<class T>
void Bubble_Sort(T A[], int n){
    for(int p=n-1; p>=0; p--){
        int flag = 0;
        for(int i=0; i<p; i++){
            if(A[i]>A[i+1]){
                int temp = A[i];
                A[i] = A[i+1];
                A[i+1] = temp;

                flag = 1;
            }
        }
        if(flag==0){
            break;
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
    Bubble_Sort<int>(A, 10);
    Printc(A, 10);

    return 0;
}





