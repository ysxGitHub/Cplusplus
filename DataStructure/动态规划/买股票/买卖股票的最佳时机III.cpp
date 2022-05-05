/*
给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
*/

#include<iostream>
#include<vector>
using namespace std;

int maxProfit1(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
    dp[0][1] = -prices[0];
    dp[0][3] = -prices[0];
    for (int i = 1; i < prices.size(); i++) {
        dp[i][0] = dp[i - 1][0];
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
    }
    return dp[prices.size() - 1][4];
}

int maxProfit2(vector<int>& prices) {
    int dp_i10 = 0, dp_i11 = INT32_MIN;
    int dp_i20 = 0, dp_i21 = INT32_MIN;
    for (int price : prices) {
        dp_i20 = max(dp_i20, dp_i21 + price);
        dp_i21 = max(dp_i21, dp_i10 - price);
        dp_i10 = max(dp_i10, dp_i11 + price);
        dp_i11 = max(dp_i11, -price);
    }
    return dp_i20;    
}


int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int maxLimit = 2; 
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(2+1, vector<int>(2)));
    
    dp[0][1][0] = dp[0][2][0] = 0;
    dp[0][1][1] = dp[0][2][1] = -prices[0];

    for(int i=1; i<n; i++){
        for(int k=maxLimit; k>=1; i--){
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            dp[i][k][1] = max(dp[i-1][k-1][0]-prices[i], dp[i-1][k][1]);
        }

    }
    return dp[n-1][maxLimit][0];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
