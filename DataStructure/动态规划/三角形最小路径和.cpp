/*
给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标
    相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，
    那么下一步可以移动到下一行的下标 i 或 i + 1 。
*/

#include <iostream>
#include <vector>
using namespace std;


int minimumTotal(vector<vector<int>>& triangle) {
    int m = triangle.size(), n = triangle.back().size();
    if(m==1) return triangle[0][0];
    vector<int>dp(n, 100000);
    dp[0] = triangle[0][0];
    int lastSize = 1;
    for(int i=1; i<m; i++){
        for(int j=triangle[i].size()-1; j>=0; j--){
            int num = triangle[i][j];
            if(j>0&&j<lastSize){
                dp[j] = min(dp[j] + num, dp[j-1] + num);
            }else if(j==0){
                dp[j] = dp[j] + num;
            }else if(j==lastSize){
                dp[j] = dp[j-1] + num;
            }
        }
        lastSize = triangle[i].size();
    }
    int ans = 100000;
    for(int i=0; i<n; i++){
        if(ans>dp[i]) ans=dp[i];
    }
    return ans;
}