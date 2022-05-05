/*
给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
    一旦你支付此费用，即可选择向上爬一个或者两个台阶。

你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。

请你计算并返回达到楼梯顶部的最低花费。
*/
#include<vector>
#include<iostream>

using namespace std;

int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    // 到达第i个台阶所花费的最少体力为 dp[i], 这里认为是第一步一定是要花费
    vector<int>dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];
    for(int i=2; i<n; i++){
        // 可能来自前一步或前两步
        dp[i] = min(dp[i-1], dp[i-2]) + cost[i];
    }
    // 取倒数第一步，第二步的最少值
    return dp[n-1]<dp[n-2]?dp[n-1]:dp[n-2];
}

int minCostClimbingStairs1(vector<int>& cost) {
    int n = cost.size();
    int dp0 = cost[0], dp1 = cost[1];
    for(int i=2; i<n; i++){
        int tmp = min(dp0, dp1) + cost[i];
        dp0 = dp1;
        dp1 = tmp;
    }
    
    return dp0<dp1?dp0:dp1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
