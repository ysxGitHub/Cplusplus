/*
给定一个整数数组 prices，其中 prices[i]表示第 i 天的股票价格 ；整数 fee
    代表了交易股票的手续费用。

你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，
    在卖出它之前你就不能再继续购买股票了。

返回获得利润的最大值。

注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。
*/
#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2));
    for(int i=0; i<n; i++){
        if(i==0){
            dp[i][0] = 0;
            dp[i][1] = -prices[i];
            continue;
        }
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
    }
    return dp[n-1][0];
}

// 空间复杂度优化版本
int maxProfit1(vector<int>& prices, int fee) {
    int n = prices.size();
    int dp_i_0 = 0, dp_i_1 = INT32_MIN;
    for (int i = 0; i < n; i++) {
        int temp = dp_i_0;
        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
        dp_i_1 = max(dp_i_1, temp - prices[i] - fee);
    }
    return dp_i_0;
}

// 贪心
int maxProfit(vector<int>& prices, int fee) {
    int result = 0;
    int minPrice = prices[0]; // 记录最低价格
    for (int i = 1; i < prices.size(); i++) {
        // 情况二：相当于买入
        if (prices[i] < minPrice) minPrice = prices[i];

        // 情况三：保持原有状态（因为此时买则不便宜，卖则亏本）
        if (prices[i] >= minPrice && prices[i] <= minPrice + fee) {
            continue;
        }

        // 计算利润，可能有多次计算利润，最后一次计算利润才是真正意义的卖出
        if (prices[i] > minPrice + fee) {
            result += prices[i] - minPrice - fee;
            minPrice = prices[i] - fee; // 情况一，这一步很关键
        }
    }
    return result;
}