/*
给你一个整数数组 nums 和一个整数 k ，按以下方法修改该数组：

选择某个下标 i 并将 nums[i] 替换为 -nums[i] 。
重复这个过程恰好 k 次。可以多次选择同一个下标 i 。

以这种方式修改数组后，返回数组 可能的最大和 。
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int largestSumAfterKNegations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for(auto&num: nums){
        if(num<0&&k>0){
            num=-num;
            --k;
        }
        sum += num;
    }
    sort(nums.begin(), nums.end());
    return sum - (k % 2 == 0 ? 0 : 2 * nums[0]);
}