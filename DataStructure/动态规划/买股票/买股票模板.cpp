/*
股票系列问题状态定义：
    dp[i][k][0 or 1]
    0 <= i <= n - 1, 1 <= k <= K
    n 为天数，大 K 为交易数的上限，0 和 1 代表是否持有股票。
股票系列问题通用状态转移方程：
    dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i])
                max( 今天选择 rest,        今天选择 sell       )

    dp[i][k][1] = max(dp[i-1][k][1], dp[i-1][k-1][0] - prices[i])
                max( 今天选择 rest,         今天选择 buy         )
通用 base case：
    dp[-1][...][0] = dp[...][0][0] = 0
    dp[-1][...][1] = dp[...][0][1] = -infinity

特化到 k = 1 的情况，状态转移方程和 base case 如下：

    状态转移方程：
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
        dp[i][1] = max(dp[i-1][1], -prices[i])

    base case：
        dp[i][0] = 0;
        dp[i][1] = -prices[i];
*/

#include<vector>
#include<iostream>

using namespace std;

// 同时考虑交易次数的限制、冷冻期和手续费
int maxProfit_all_in_one(int max_k, vector<int>& prices, int cooldown, int fee) {
    int n = prices.size();
    if (n <= 0) {
        return 0;
    }
    if (max_k > n / 2) {
        // 交易次数 k 没有限制的情况
        return maxProfit_k_inf(prices, cooldown, fee);
    }

    vector<vector<vector<int>>>dp(n, vector<vector<int>>(max_k+1, vector<int>(2)));
    // k = 0 时的 base case
    for (int i = 0; i < n; i++) {
        dp[i][0][1] = INT32_MIN;
        dp[i][0][0] = 0;
    }

    for (int i = 0; i < n; i++) 
        for (int k = max_k; k >= 1; k--) {
            if (i - 1 == -1) {
                // base case 1
                dp[i][k][0] = 0;
                dp[i][k][1] = -prices[i] - fee;
                continue;
            }
            // 包含 cooldown 的 base case
            if (i - cooldown - 1 < 0) {
                // base case 2
                dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
                // 别忘了减 fee
                dp[i][k][1] = max(dp[i-1][k][1], -prices[i] - fee);
                continue;
            }
            dp[i][k][0] = max(dp[i-1][k][0], dp[i-1][k][1] + prices[i]);
            // 同时考虑 cooldown 和 fee
            dp[i][k][1] = max(dp[i-1][k][1], dp[i-cooldown-1][k-1][0] - prices[i] - fee);     
        }
    return dp[n - 1][max_k][0];
}

// k 无限制，包含手续费和冷冻期
int maxProfit_k_inf(vector<int>& prices, int cooldown, int fee) {
    int n = prices.size();
    vector<vector<int>>dp(n, vector<int>(2));
    for (int i = 0; i < n; i++) {
        if (i - 1 == -1) {
            // base case 1
            dp[i][0] = 0;
            dp[i][1] = -prices[i] - fee;
            continue;
        }

        // 包含 cooldown 的 base case
        if (i - cooldown - 1 < 0) {
            // base case 2
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            // 别忘了减 fee
            dp[i][1] = max(dp[i-1][1], -prices[i] - fee);
            continue;
        }
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        // 同时考虑 cooldown 和 fee
        dp[i][1] = max(dp[i - 1][1], dp[i - cooldown - 1][0] - prices[i] - fee);
    }
    return dp[n - 1][0];
}