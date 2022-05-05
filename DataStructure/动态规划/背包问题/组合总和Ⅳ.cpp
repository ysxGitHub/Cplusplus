/*
给你一个由 不同 整数组成的数组 nums ，和一个目标整数 target 。
    请你从 nums 中找出并返回总和为 target 的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？
    如果允许负数出现，需要向题目中添加哪些限制条件？
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 超时
void backtrack(vector<int>& nums, int target, int& ans){
    if(target==0){
        ans++;
        return;
    }
    for(auto&n: nums){
        if(target-n<0){continue;}
        backtrack(nums, target-n, ans);
    }
}

int combinationSum41(vector<int>& nums, int target) {
    int ans=0;
    backtrack(nums, target, ans);
    return ans;
}

// 组合问题，考虑顺序
int combinationSum4(vector<int>& nums, int target) {
    vector<double>dp(target+1, 0);
    // 只有当不选取任何元素时，元素之和才为 0，因此只有 1 种方案。
    dp[0] = 1;
    for(int i=1; i<=target; i++){
        for(auto&num: nums){
            if(i>=num){
                // 在计算 dp[i]dp[i] 时，应该计算所有的 dp[i-num]之和。
                dp[i] += dp[i-num];
            }
        }
    }
    return dp[target];
}


int main(int argc, char const *argv[])
{
    vector<int>nums = {1,2,3}; 
    int target = 4;
    cout<<combinationSum4(nums, target);
    return 0;
}
