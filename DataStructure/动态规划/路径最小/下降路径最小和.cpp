/*
给你一个 n x n 的 方形 整数数组 matrix ，请你找出并返回通过 matrix 的下降路径 的 最小和 。

下降路径 可以从第一行中的任何元素开始，并从每一行中选择一个元素。
    在下一行选择的元素和当前行所选元素最多相隔一列（即位于正下方或者沿对角线向左或者向右的第一个元素）。
    具体来说，位置 (row, col) 的下一个元素应当是 (row + 1, col - 1)、(row + 1, col) 
    或者 (row + 1, col + 1) 。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int dp(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>&memo){
    int size = matrix.size();
    if(i>=size||j<0||j>=size){
        return 20000;
    }
    int cur = matrix[i][j];
    if(memo[i][j]!=30000){
        return memo[i][j];
    }
    int a = dp(matrix, i+1, j-1, memo); 
    int b = dp(matrix, i+1, j+1, memo);
    int c = dp(matrix, i+1, j, memo);
    int Min = min(min(a,b),c);
    if(Min==20000){
        memo[i][j] = cur;
    }else{
        memo[i][j] = cur+Min;
    }
    return memo[i][j];
}

int minFallingPathSum(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if(n==1){
        return matrix[0][0];
    }
    int res=20000;
    vector<vector<int>> memo(n, vector<int>(n, 30000));
    for(int j=0; j<n; j++){
        res = min(res, dp(matrix, 0, j, memo));
    }
    return res;
}

int main(int argc, char const *argv[])
{

    vector<vector<int>> matrix = {{100,-42,-46,-41},{31,97,10,-10},{-58,-51,82,89},{51,81,69,-51}};
    cout<<minFallingPathSum(matrix);
 
    return 0;
}
