/*
给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，
    且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。
*/

#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n));
    int up = 0, down = n-1, left = 0, right = n-1, k=1;
    while(1){
        for(int i=left; i<=right&&k<=n*n; ++i){
            ans[up][i] = k++;
        }
        ++up;
        for(int i=up; i<=down&&k<=n*n; ++i){
            ans[i][right] = k++;
        }
        --right;
        for(int i=right; i>=left&&k<=n*n; --i){
            ans[down][i] = k++;
        }
        --down;
        for(int i=down; i>=up&&k<=n*n; --i){
            ans[i][left] = k++;
        }     
        ++left;
        if(left>right){
            break;
        }       
    }
    return ans;
}




int main(int argc, char const *argv[])
{

    return 0;
}
