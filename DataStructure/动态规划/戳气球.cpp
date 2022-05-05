/*
有 n 个气球，编号为0 到 n - 1，每个气球上都标有一个数字，这些数字存在数组 nums 中。

现在要求你戳破所有的气球。戳破第 i 个气球，你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 
    枚硬币。 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号。
    如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球。

求所能获得硬币的最大数量。
*/
#include<vector>
#include<iostream>
using namespace std;

int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int>points(n+2);
    // 将原来的数组头尾分别填充 1 个硬币
    points[0] = 1, points[n+1] = 1;
    // dp[i][j] 表示 戳破 (i, j) 之间的气球可以获得的最多硬币数
    vector<vector<int>>dp(n+2, vector<int>(n+2));
    for(int i=1; i<n+1; i++) points[i] = nums[i];
    // 从下往上遍历
    for(int i=n+1; i>=0; i--){
        for(int j=i+1; j<n+2; j++){
            for(int k=i+1; k<j; k++){
                // 戳破 (i, k) 之间的气球可以获得的最多硬币数 + 
                // 戳破 (k, j) 之间的气球可以获得的最多硬币数 +
                // 戳破 第 k 个气球可以获得的硬币数
                dp[i][j] = max(dp[i][j], 
                    dp[i][k]+dp[k][j]+points[i]*points[j]*points[k]);
            }
        }
    }
    // 戳破 (0,n+1) 之间的气球可以获得的最多硬币数
    return dp[0][n+1];
}
