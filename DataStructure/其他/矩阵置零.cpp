/*
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
*/
#include <iostream>
#include <vector>
using namespace std;

// O(m*n)
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool row0 = 0, col0 = 0;
    // 先检查第一行或第一列是否存在 0
    for(int i=0; i<m; i++){
        if(matrix[i][0]==0) {
            row0 = 1;
            break;
        }
    }
    for(int j=0; j<n; j++){
        if(matrix[0][j]==0){
            col0 = 1;
            break;
        }
    }
    // 将该数对应的 第一行 和 第一列的位置 置 1
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0, matrix[0][j] = 0;
            }
        }
    }
    // 根据第一行第一列的 数值去 将数组置零
    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][0] ==0||matrix[0][j] == 0){
                matrix[i][j] = 0;
            }
        }
    }
    // 判断第一行第一列是否出现 0
    if(row0){
        for(int i=0; i<m; i++){
            matrix[i][0] = 0;
        }
    }
    if(col0){
        for(int j=0; j<n; j++){
            matrix[0][j] = 0;
        }
    }
}