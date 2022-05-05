/*
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），
    返回其最大和。

子数组 是数组中的一个连续部分。
*/

#include<iostream>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
    int maxsum = INT32_MIN;
    int sum = 0;
    for(int i=0; i<nums.size(); i++){
        sum += nums[i];
        if(sum<nums[i]){
            sum = nums[i];
        }
        maxsum = max(maxsum, sum);
    }
    return maxsum;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
