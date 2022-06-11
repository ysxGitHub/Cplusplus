/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。
请你设计时间复杂度为 O(n) 的算法解决本问题
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = 0, i = 0;
    vector<int>ans(n);
    while(left<n&&nums[left]<0) left++;
    right = left;
    left--;
    while(right<n&&left>=0){
        if(abs(nums[right])>abs(nums[left])){
            ans[i++] = nums[left]*nums[left];
            left--;
        }else{
            ans[i++] = nums[right]*nums[right];
            right++;
        }
    }
    while(left>=0){
        ans[i++] = nums[left]*nums[left];
        left--;
    }
    while(right<n){
        ans[i++] = nums[right]*nums[right];
        right++;
    }
    return ans;
}

vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int left = 0, right = n-1, k = n-1;
    vector<int>ans(n);
    while(left<=right){
        int ll = nums[left]*nums[left], rr = nums[right]*nums[right];
        if(ll>rr){
            ans[k--] = ll;
            left++;
        }else{
            ans[k--] = rr;
            right--;
        }
    }
    return ans;
}