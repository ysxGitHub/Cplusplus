/*
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
    并返回其长度。如果不存在符合条件的子数组，返回 0 。
*/
#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
    int n = nums.size();
    int left = 0 , ans = INT32_MAX, sum = 0;
    for(int right=0; right<n; right++){
        sum+=nums[right];
        while(sum>=target){
            ans = min(ans, right-left+1);
            sum -= nums[left];
            left++;
        }
    }
    return ans==INT32_MAX?0:ans;
}