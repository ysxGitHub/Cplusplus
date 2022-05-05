/*
给你一个 只包含正整数 的 非空 数组 nums 。
    请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

// 可以先求sum，再寻找nums中元素之和等于sum/2是否存在，
    0-1背包问题，且不能重复使用元素
*/

#include<iostream>
#include<vector>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = 0;
    for(auto & n : nums){
        sum += n;
    }
    if(sum%2==1){return 0;}
    int halfsum = sum/2;
    vector<bool>dp(halfsum+1, 0);
    dp[0] = 1;
    for(auto & n : nums){
        for(int i=halfsum; i >= n; i--){
            dp[i] = dp[i - n];
        }
    }
    return dp[halfsum];
}

int main(int argc, char const *argv[])
{
    vector<int>nums = {1,2,3,4};
    cout<<canPartition(nums);
    return 0;
}
