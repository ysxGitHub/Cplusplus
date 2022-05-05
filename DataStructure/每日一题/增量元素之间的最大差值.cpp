/*
给你一个下标从 0 开始的整数数组 nums ，该数组的大小为 n ，
    请你计算 nums[j] - nums[i] 能求得的 最大差值 ，其中 0 <= i < j < n 且 nums[i] < nums[j] 。

返回 最大差值 。如果不存在满足要求的 i 和 j ，返回 -1 。
*/

#include<vector>
#include<iostream>

using namespace std;

// 暴力解法
int maximumDifference1(vector<int>& nums) {
    int maxdiff = -1;
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums.size(); j++){
            if(j>i && nums[j] > nums[i])
            maxdiff = max(maxdiff, nums[j] - nums[i]);
        }
    }
    return maxdiff;
}

// 最小前缀 [2,10,1,5]
int maximumDifference(vector<int>& nums) {
    int maxdiff = -1;
    // 保存0...i之间最小的数
    int premin = nums[0];
    for(int i=1; i<nums.size(); i++){
        if(nums[i] > premin){
            // 
            maxdiff = max(maxdiff, nums[i] - premin);
        }else{
            // 将当前的premin替换
            premin = nums[i];
        }
    } 
    return maxdiff;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
