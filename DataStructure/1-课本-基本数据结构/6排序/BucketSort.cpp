#include<iostream>
using namespace std;
#define M 10

template<class T>
class Node{
public:
    T data=0;
    Node<T> *Next=NULL;
};

// 这种桶排序适合M<<N，如10000个学生(N)的英语成绩(M)
template<class T>
void Bucket_Sort(T*A, int N){
    
    Node<T>* Node_Arr = new Node<T>[M];
    for(int i=0; i<N; i++){
        Node_Arr[A[i]].data +=1;
    }

    for(int j=0; j<M; j++){
        for(int k=0; k<Node_Arr[j].data; k++){
            cout<<j<<"  ";
        }
    }
    
    delete[] Node_Arr;
}


int main(int argc, char const *argv[])
{
    int A[] = {1,2,3,4,5,6,7,8,9,0,1,3,2,4,5,6,9,8,7,9,1,2,8};
    int N = sizeof(A)/sizeof(int);
    Bucket_Sort(A, N);

    return 0;
}
