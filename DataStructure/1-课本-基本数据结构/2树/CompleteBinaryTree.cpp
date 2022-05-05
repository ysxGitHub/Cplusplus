#include<iostream>
// #include<algorithm>
#include<math.h>
using namespace std;
#define min(a,b) (a>=b?b:a)

int A[] = {0,1,2,3,4,5,6,7,8,9};
int T[10] = {};

int GetLeftLength(int n){
    int H = log2(n + 1);
    int x = n + 1- pow(2, H);
    return pow(2, H-1) - 1 + min(x, pow(2, H-1));
}

void com_tree(int ALeft, int ARight, int TRoot){
    int n = ARight - ALeft + 1;
    if(n==0){
        return;
    }
    // 计算出n个节点的树其左子树有多少个节点
    int L = GetLeftLength(n);
    T[TRoot] = A[ALeft + L];
    int LeftRoot = TRoot*2 + 1;
    int RightRoot = LeftRoot + 1;
    com_tree(ALeft, ALeft+L-1, LeftRoot);
    com_tree(ALeft+L+1, ARight, RightRoot); 
}


int compare(const void*a, const void*b)
{
    return *(int*)a - *(int*)b;
}

int main(int argc, char const *argv[])
{
    qsort(A, 10, sizeof(int), compare);
    com_tree(0, 9, 0);
    // 层序遍历的结果
    for(auto& elem:T){
        cout<<elem<<" ";
    }
    return 0;
}
