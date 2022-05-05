/*
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/

//类似 剑指 Offer 47. 礼物的最大价值

#include<iostream>
#include<vector>
using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>dp(m, vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(i==0&&j!=0){
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            if(i!=0&&j==0){
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            if(i!=0&&j!=0){
                dp[i][j] = min(dp[i][j-1], dp[i-1][j]) + grid[i][j];
            }
        }
    }
    return dp[m-1][n-1];
}

int main(int argc, char const *argv[])
{

    return 0;
}
