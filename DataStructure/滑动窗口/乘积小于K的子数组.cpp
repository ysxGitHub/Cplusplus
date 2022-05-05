/*
给你一个整数数组 nums 和一个整数 k ，请你返回子数组内所有元素的乘积严格小于 k 的连续子数组的数目。
*/
#include <iostream>
#include <vector>
using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    if(k==0) return 0;
    int n = nums.size(), left = 0;
    int mul = 1, cnt = 0;
    for(int right=0; right<n; right++){
        mul*=nums[right];
        while(mul>=k&&left<=right){
            mul/=nums[left++];
        }
        /*
        [3,4,5,6]
        假设nums[r]==6, l已经移动到 mul<k 的地方
        r 之前的 组合已经考虑了, 现在计算 [l,r] 之间的组合
        [3,4,5,6]
        [4,5,6]
        [5,6]
        [6]
        即 r-l+1
        */
        cnt+=right-left+1;
    }
    return cnt;
}