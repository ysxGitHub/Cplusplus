/*
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
    这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
    如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，
    今晚能够偷窃到的最高金额。

*/
#include<iostream>
#include<vector>
using namespace std;

/*
思路：比较 从[1, n-1] 和 [0, n-2] 偷钱那个多, 这样就类似 I
*/ 

int rob(vector<int>& nums) {
    int n = nums.size();
    if(n==1){return nums[0];}
    if(n==2){return nums[0]>nums[1]?nums[0]:nums[1];}
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = nums[1];
    if(dp[0]>dp[1]) dp[1] = dp[0];
    for(int i=2; i<n-1; i++){
        if(dp[i-2]+nums[i]>dp[i-1]){
            dp[i] = dp[i-2] + nums[i];
        }else{
            dp[i] = dp[i-1];
        }
    }
    int maxMeny = dp[n-2];
    dp[1] = nums[1];
    dp[2] = nums[2];        
    if(dp[1]>dp[2]) dp[2] = dp[1];
    for(int i=3; i<n; i++){
        if(dp[i-2]+nums[i]>dp[i-1]){
            dp[i] = dp[i-2] + nums[i];
        }else{
            dp[i] = dp[i-1];
        }
    }
    return maxMeny > dp[n-1] ? maxMeny : dp[n-1];       
}