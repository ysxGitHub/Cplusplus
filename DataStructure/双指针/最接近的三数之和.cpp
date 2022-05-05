/*
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，
    使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。

*/

#include<iostream>
#include<vector>
using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int dif = 10e6, ans = 0;
    int n = nums.size();
    for(int i=0; i<n; i++) {
        if(i>0&&nums[i]==nums[i-1]) continue;
        int newTarget = target-nums[i];
        int left = i+1, right = n-1;
        while(left<right){
            int sum = nums[left] + nums[right];
            int leftT = nums[left], rightT = nums[right];
            if(sum<newTarget){
                while(left<right&&nums[left]==leftT) left++;
            }else{
                while(left<right&&nums[right]==rightT) right--;
            }
            if(abs(target-sum-nums[i])<dif){
                dif = abs(target-sum-nums[i]);
                ans = sum+nums[i];
            }
        }
    }
    return ans;
}