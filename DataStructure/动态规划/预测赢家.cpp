/*
给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏。

玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手。开始时，两个玩家的初始分值都是 0 。
    每一回合，玩家从数组的任意一端取一个数字（即，nums[0] 或 nums[nums.length - 1]），取到的数字将会从数组中移除（数组长度减 1 ）。玩家选中的数字将会加到他的得分上。当数组中没有剩余数字可取时，游戏结束。

如果玩家 1 能成为赢家，返回 true 。如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true 。
    你可以假设每个玩家的玩法都会使他的分数最大化。
*/

#include<iostream>
#include<vector>
using namespace std;

// 基于从 0 到 n-1 的数组，当前选择的玩家所能赢对方的分数
int total(vector<int>& nums, int start, int end, vector<vector<int>>&memo) {
    if(start>end) return 0;

    if(memo[start][end]!=INT_MAX) return memo[start][end];

    // 选择左端，获得 nums[start]， 之后输掉 total(start+1, end) 分
    int chooseLeft = nums[start] - total(nums, start+1, end, memo);
    // 选择右端，获得 nums[end]， 之后输掉 total(start, end-1) 分
    int chooseRight = nums[end] - total(nums, start, end-1, memo);
    // 返回较大者，即在 [start,end] 数组游戏中胜过对方的分数
    memo[start][end] = max(chooseLeft, chooseRight);
    return memo[start][end];
}

bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>memo(n, vector<int>(n, INT_MAX));
    // 基于整个数组玩这个游戏，玩家1先手，>=0就获胜
    return total(nums, 0, n - 1, memo) >= 0;
}


// 状态转移方程：dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1])
bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>>dp(n, vector<int>(n));

    // dp[i][j]：作为先手，在区间 nums[i..j] 里进行选择可以获得的相对分数
    for (int i = 0; i < n; i++) {
        dp[i][i] = nums[i];
    }
    // 从下之上, 从左到右
    for (int i = n - 2; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            // 当前玩家与另一个玩家的分数之差的最大值, 另一个玩家可以拿 i+1 或者 j-1
            dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
        }
    }
    return dp[0][n - 1] >= 0;
}

