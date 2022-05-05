#include <iostream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
#define M 1000


/*
基数排序适合
M>>N
如30个学生(N)的家庭资产(M)

*/

template<class T>
void Radix_Sort(T* A, int N) {
    int it = 0;
    //需要遍历的次数由数组最大值的位数来决定
    for (int it = 1; M / it > 0; it = it * 10)
    {
        vector<queue<T>> container(10);
        for (int i = 0; i < N; i++) {
            int digit = (A[i] / it) % 10;
            container[digit].push(A[i]);
        }

        int m = 0;
        for (int k = 0; k < 10; k++) {
            while (!container[k].empty()) {
                A[m++] = container[k].front();
                container[k].pop();
            }
        }
    }
}

template<class T>
void Printc(T A[], int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << "  ";
    }
    cout << endl;
}


int main(int argc, char const* argv[])
{
    int A[] = { 100,99,2,200,67,3,900,21,400,1,17,5,7,1000};
    int N = sizeof(A) / sizeof(int);
    Radix_Sort(A, N);
    Printc(A, N);

    return 0;
}
