/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
    返回其最大和。

子数组 是数组中的一个连续部分
*/
#include<iostream>
#include<vector>

using namespace std;

// 暴力解法
int maxSubArray1(vector<int>& nums) {
    int ans=-20000;
    for(int i=0; i<nums.size(); i++){
        int tmp=0;
        for(int j=i; j<nums.size(); j++){
            tmp += nums[j];
            ans = max(ans, tmp);
        }
    }
    return ans;
}

// 分而治之
int CrossMax(vector<int>& nums, int left, int mid, int right){
    int leftSumMax = nums[mid];
    int leftSum = 0;
    int rightSumMax = 0;
    int rightSum = 0;
    for(int i=mid; i>=left; i--){
        leftSum += nums[i];
        if(leftSum>leftSumMax){
            leftSumMax = leftSum;
        }
    }

    for(int j=mid+1; j<=right; j++){
        rightSum += nums[j];
        if(rightSum>rightSumMax){
            rightSumMax = rightSum;
        }
    }    
    return leftSumMax+rightSumMax;
}

int findMax(vector<int>& nums, int left, int right){
    if(left==right){
        return nums[left];
    }
    int mid = (left+right)/2;
    int leftMax = findMax(nums, left, mid);
    int rightMax = findMax(nums, mid+1, right);
    int crossNum = CrossMax(nums, left, mid, right);
    return max(max(leftMax, rightMax), crossNum);
}
int maxSubArray(vector<int>& nums) {

    return findMax(nums, 0, nums.size()-1);
}

// 类似DP但不是DP
int maxSubArray2(vector<int>& nums) {
    int n = nums.size();
    int res = 0;
    int sums = 0;
    int maxRes = -20000;
    for(int i=0; i<n; i++){
        sums += nums[i];
        if(sums>nums[i]){
            res = sums;
        }else{
            res = nums[i];
            sums = nums[i];
        }
        maxRes = max(maxRes, res);
    }
    return maxRes;
}


int main(int argc, char const *argv[])
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(nums);
    return 0;
}
