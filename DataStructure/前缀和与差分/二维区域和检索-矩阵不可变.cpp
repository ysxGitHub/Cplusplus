/*
给定一个二维矩阵 matrix，以下类型的多个请求：

计算其子矩形范围内元素的总和，该子矩阵的 左上角 为 (row1, col1) ，右下角 为 (row2, col2) 。
实现 NumMatrix 类：

NumMatrix(int[][] matrix) 给定整数矩阵 matrix 进行初始化
int sumRegion(int row1, int col1, int row2, int col2) 返回 左上角 (row1, col1) 、
    右下角 (row2, col2) 所描述的子矩阵的元素 总和 。
*/

#include<iostream>
#include<vector>

using namespace std;

class NumMatrix {
vector<vector<int>> sum_arr;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(); // 行
        int n = matrix[0].size(); //列
        sum_arr.resize(m, vector<int>(n));
        sum_arr[0][0] = matrix[0][0];
        for(int i=1; i<m; i++){
            sum_arr[i][0] = sum_arr[i-1][0] + matrix[i][0];
        }
        for(int j=1; j<n; j++){
            sum_arr[0][j] = sum_arr[0][j-1] + matrix[0][j];
        }
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                sum_arr[i][j] = sum_arr[i-1][j] + sum_arr[i][j-1] - sum_arr[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(!row1&&!col1){
            return sum_arr[row2][col2];
        }
        if(!row1){
            return (sum_arr[row2][col2] - sum_arr[row2][col1-1]);
        }
        if(!col1){
            return (sum_arr[row2][col2] - sum_arr[row1-1][col2]);
        }
        return (sum_arr[row2][col2] - sum_arr[row2][col1-1] - sum_arr[row1-1][col2] + sum_arr[row1-1][col1-1]);
    }
};

int main(int argc, char const *argv[])
{
    vector<vector<int>> matrix{{1,2,3},{4,5,6},{7,8,9}};
    NumMatrix nm(matrix);
    cout<<nm.sumRegion(0,1,1,2);
    return 0;
}
