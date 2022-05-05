/*
给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。

你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。
    设计一个算法来计算你所能获取的最大利润。

返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

*/
#include<vector>
#include<iostream>

using namespace std;

int maxProfit1(vector<int>& prices) {
    int n = prices.size();
    if(n<=1) return 0;
    int maxMoney = 0, minMoney=prices[0];
    for(int i=1; i<n; i++){
        maxMoney = max(maxMoney, prices[i] - minMoney);
        minMoney = min(minMoney, prices[i]);
    }
    return maxMoney;
}

// 交易总数 k 为 1
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2));
    // 第 0 天不买, 没有股票
    dp[0][0] = 0;
    // 第 0 天买, 有股票
    dp[0][1] = -prices[0];
    for(int i=1; i<n; i++){
        //         i-1 天 没有股票,  有则进行卖出     
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
        //         i-1 天 有 股票,  没有则进行买入
        dp[i][1] = max(dp[i-1][1], -prices[i]);   
        // dp[i-1][k-1][0]  k=1   dp[i-1][0][0] - prices[i] = - prices[i]
    }
    return dp[n-1][0];
}


int main(int argc, char const *argv[])
{
    vector<int> prices = {7,1,5,3,6,4};
    cout<<maxProfit1(prices)<<endl;
    cout<<maxProfit(prices);
    return 0;
}
