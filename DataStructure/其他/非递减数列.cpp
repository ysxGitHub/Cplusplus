/*
给你一个长度为 n 的整数数组 nums ，请你判断在 最多 改变 1 个元素的情况下，
    该数组能否变成一个非递减数列。

我们是这样定义一个非递减数列的： 
    对于数组中任意的 i (0 <= i <= n-2)，总满足 nums[i] <= nums[i + 1]。
*/

#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;


bool checkPossibility1(vector<int>& nums) {
    int n = nums.size();
    vector<int> nums2, nums3;
    if(n<=2){return 1;}
    nums2.emplace_back(nums[0]);
    for(int i=1; i<n; i++){
        if(nums[i]<nums[i-1]) {
            nums2.pop_back();
            nums2.emplace_back(nums[i]);
        }else{
            nums2.emplace_back(nums[i]);
            nums3.emplace_back(nums[i]);
        }
    }
    if(nums2.size()<n-1){return false;}
    bool a=1, b=1;
    for(int i=1; i<nums2.size(); i++){
        if(nums2[i]<nums2[i-1]) {
            a=0;
            break;
        }
    }
    for(int i=1; i<nums3.size(); i++){
        if(nums3[i]<nums3[i-1]) {
            b=0;
            break;
        }
    }
    return a|b;
}

bool checkPossibility(vector<int>& nums) {
    int x=0, y=0;
    for(int i=0; i<nums.size()-1; i++){
        if(nums[i]>nums[i+1]){
            x = nums[i], y = nums[i+1];
            nums[i] = y;
            if(is_sorted(nums.begin(), nums.end())) return true;
            nums[i] = x;
            nums[i+1] = x;
            return is_sorted(nums.begin(), nums.end());
        }
    }
    return true;
}

