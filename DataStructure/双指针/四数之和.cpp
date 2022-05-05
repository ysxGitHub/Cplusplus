/*
给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
    请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
    （若两个四元组元素一一对应，则认为两个四元组重复）：

0 <= a, b, c, d < n
a、b、c 和 d 互不相同
nums[a] + nums[b] + nums[c] + nums[d] == target
你可以按 任意顺序 返回答案 。
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;


vector<vector<int>> twoSum(vector<int>& nums, int left, int right, int target){
    vector<vector<int>> twonums;
    while(left < right){
        int sum = nums[left] + nums[right];
        int tmpL = nums[left], tmpR = nums[right];
        if(sum < target){
            while(left < right && tmpL == nums[left]){++left; }
        }
        else if(sum > target){
            while(left < right && tmpR == nums[right]){--right; }
        }
        else{
            twonums.push_back({nums[left], nums[right]});
            while(left < right && tmpL == nums[left]){++left; }
            while(left < right && tmpR == nums[right]){--right; }
        }
    }
    return twonums;
}

vector<vector<int>> threeSum(vector<int>& nums, int left, int right, int target){
    vector<vector<int>> threenums;
    for(int i=left; i<right; i++){
        if(i > left && nums[i-1] == nums[i]) {continue; }
        vector<vector<int>> twonums = twoSum(nums, i+1, right, target - nums[i]);
        for(vector<int>& two: twonums){
            two.push_back(nums[i]);
            threenums.push_back(two);
        }
    }
    return threenums;
}


vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> fournums;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(i>0 && nums[i-1] == nums[i]) {continue; }
        vector<vector<int>> threenums = threeSum(nums, i+1, n-1, target - nums[i]);
        for(vector<int>& three: threenums){
            three.push_back(nums[i]);
            fournums.push_back(three);
        }
    }

    return fournums;
}


/* 
    nSum
注意：调用这个函数之前一定要先给 nums 排序 
*/
vector<vector<int>> nSumTarget(
    vector<int>& nums, int n, int start, int target) {

    int sz = nums.size();
    vector<vector<int>> res;
    // 至少是 2Sum，且数组大小不应该小于 n
    if (n < 2 || sz < n) return res;
    // 2Sum 是 base case
    if (n == 2) {
        // 双指针那一套操作
        int lo = start, hi = sz - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            int left = nums[lo], right = nums[hi];
            if (sum < target) {
                while (lo < hi && nums[lo] == left) lo++;
            } else if (sum > target) {
                while (lo < hi && nums[hi] == right) hi--;
            } else {
                res.push_back({left, right});
                while (lo < hi && nums[lo] == left) lo++;
                while (lo < hi && nums[hi] == right) hi--;
            }
        }
    } else {
        // n > 2 时，递归计算 (n-1)Sum 的结果
        for (int i = start; i < sz; i++) {
            vector<vector<int>> 
                sub = nSumTarget(nums, n - 1, i + 1, target - nums[i]);
            for (vector<int>& arr : sub) {
                // (n-1)Sum 加上 nums[i] 就是 nSum
                arr.push_back(nums[i]);
                res.push_back(arr);
            }
            while (i < sz - 1 && nums[i] == nums[i + 1]) i++;
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
