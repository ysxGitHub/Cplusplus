/*
给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​

设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:

卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/
#include<iostream>
#include<vector>
using namespace std;


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2));
    for(int i=0; i<n; i++){
        if(i==0){
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        if(i==1){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
            continue;
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        dp[i][1] = max(dp[i-2][0] - prices[i], dp[i-1][1]);
    }
    return dp[n-1][0];
}

// 空间复杂度优化版本
int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT32_MIN;
    int dp_pre_0 = 0; // 代表 dp[i-2][0]
    for (int i = 0; i < n; i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
        dp_pre_0 = temp;
    }
    return dp_i_0;
}