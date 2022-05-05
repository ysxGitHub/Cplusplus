#include<iostream>
#include<algorithm>
using namespace std;

// 时间复杂度为O(N^2)
template<class T> 
void Selection_Sort(T arr[], int n) {
        for (int i = 0; i < n - 1; i++) {
                int min = i;
                for (int j = i + 1; j < n; j++){
                    if (arr[j] < arr[min]){
                        min = j;
                    }      
                }
                swap(arr[i], arr[min]);
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
    Selection_Sort<int>(A, 10);
    Printc(A, 10);
    return 0;
}
