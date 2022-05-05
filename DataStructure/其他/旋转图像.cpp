/*
给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。

你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要 使用另一个矩阵来旋转图

*/
#include<vector>
using namespace std;

// 法1：先沿主对角线交换元素，在按列交换
void rotate(vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size(); i++){
        for(int j=i+1; j<matrix.size(); j++){
            if(i==j){continue;}
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix.size()/2; j++){
            swap(matrix[i][j], matrix[i][matrix.size()-j-1]);
        }
    }
}

// 法2：每一次原地交换四个位置
void rotate1(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i=0; i<n/2; ++i){
        for(int j=0; j<(n+1)/2; ++j){
            // (0,1)
            int tmp = matrix[i][j];
            // (0,1)<---(1,0)
            matrix[i][j] = matrix[n-j-1][i];
            // (1,0)<---(2,1)
            matrix[n-j-1][i] = matrix[n-i-1][n-j-1];
            // (2,1)<---(1,2)
            matrix[n-i-1][n-j-1] = matrix[j][n-i-1];
            // (1,2)<---(0,1)
            matrix[j][n-i-1] = tmp;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
