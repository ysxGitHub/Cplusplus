/*
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。
*/


#include<iostream>
#include<vector>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> ans;
    ans.emplace_back(mat[0][0]);
    bool flag = 1;
    int i=0, j=0;
    for(int k = 1; k < m + n - 1; k++){
        if(flag){
            j = k;
            if(k>=n) j = n-1;
            i = k - j;
            while(j>=0&&j<n&&i>=0&&i<m){
                ans.emplace_back(mat[i][j]);
                i++,j--;
            }
            flag=0;
        }else{
            i = k; 
            if(k>=m) i = m-1;
            j = k - i;
            while(j>=0&&j<n&&i>=0&&i<m){
                ans.emplace_back(mat[i][j]);
                i--,j++;
            }
            flag=1;                 
        }

    }
    return ans;
}