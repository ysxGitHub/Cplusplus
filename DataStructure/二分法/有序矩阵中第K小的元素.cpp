
/*
给你一个 n x n 矩阵 matrix ，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。
请注意，它是 排序后 的第 k 小元素，而不是第 k 个 不同 的元素。

你必须找到一个内存复杂度优于 O(n2) 的解决方案。
*/
#include <vector>
#include <iostream>

using namespace std;

bool check(vector<vector<int>>& matrix, int mid, int k, int n){
    int i = n-1, j = 0, num=0;
    while(i>=0&&j<n){
        if(matrix[i][j]<=mid){
            num+=i+1;
            j++;
        }else{
            i--;
        }
    }
    return num>=k;
}

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int left = matrix[0][0], right = matrix[n-1][n-1];
    while(left<=right){
        int mid = left + ((right-left)>>1);
        if(check(matrix, mid, k, n)){
            right=mid-1;
        }else{
            left=mid+1;
        }
    }
    return left;
}