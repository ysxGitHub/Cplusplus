/*
给定一个未排序的整数数组 nums ， 返回最长递增子序列的个数 。

注意 这个数列必须是 严格 递增的。
*/

#include <iostream>
#include <vector>
using namespace std;


/*
    先看300.最长递增子序列

    定义 dp[i] 表示以 nums[i] 结尾的最长上升子序列的长度，
    cnt[i] 表示以 nums[i] 结尾的最长上升子序列的个数。
*/

int findNumberOfLIS(vector<int> &nums) {
    int n = nums.size(), maxLen = 0, ans = 0;
    vector<int> dp(n), cnt(n);

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        cnt[i] = 1;
        for (int j = 0; j < i; ++j) {
            if (nums[i] > nums[j]) {
                if (dp[j] + 1 > dp[i]) {
                    // 以 nums[i] 结尾 重新计数
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j]; // 重置计数
                } else if (dp[j] + 1 == dp[i]) {
                    // 以 nums[i] 结尾的 +1
                    cnt[i] += cnt[j];
                }
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            ans = cnt[i]; // 重置计数
        } else if (dp[i] == maxLen) {
            ans += cnt[i];
        }
    }
    return ans;
}
