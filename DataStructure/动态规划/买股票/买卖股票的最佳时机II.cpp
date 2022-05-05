/*
给定一个数组 prices ，其中 prices[i] 表示股票第 i 天的价格。

在每一天，你可能会决定购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。
    你也可以购买它，然后在 同一天 出售。
返回 你能获得的 最大 利润 。
*/
#include<iostream>
#include<vector>

using namespace std;

int maxProfit1(vector<int>& prices) {
    int s = 0; 
    for(int i = 0;i<prices.size()-1;i++){
        if(prices[i+1]-prices[i]>0){ 
            s+=prices[i+1]-prices[i]; 
        } 
    } 
    return s; 
}

// 交易总数 k 为 正无穷
int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for(int i=1; i<n; i++){
        dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
        dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
    }
    return dp[n-1][0];
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
