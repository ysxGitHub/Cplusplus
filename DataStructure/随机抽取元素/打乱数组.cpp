/*
给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。打乱后，
    数组的所有排列应该是 等可能 的。

实现 Solution class:

    Solution(int[] nums) 使用整数数组 nums 初始化对象
    int[] reset() 重设数组到它的初始状态并返回
    int[] shuffle() 返回数组随机打乱后的结果
*/
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int>shusum = nums;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int r = rand()%(n-i) + i;
            swap(shusum[i], shusum[r]);
        }
        return shusum;
    }
};

