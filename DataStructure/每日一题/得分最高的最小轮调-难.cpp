/*
给你一个数组 nums，我们可以将它按一个非负整数 k 进行轮调，这样可以使数组变为 
    [nums[k], nums[k + 1], ... nums[nums.length - 1], nums[0], nums[1], ..., nums[k-1]]
     的形式。此后，任何值小于或等于其索引的项都可以记作一分。

例如，数组为 nums = [2,4,1,3,0]，我们按 k = 2 进行轮调后，它将变成 [1,3,0,2,4]。这将记为 3 分，
    因为 1 > 0 [不计分]、3 > 1 [不计分]、0 <= 2 [计 1 分]、2 <= 3 [计 1 分]，4 <= 4 [计 1 分]。
在所有可能的轮调中，返回我们所能得到的最高分数对应的轮调下标 k 。如果有多个答案，
    返回满足条件的最小的下标 k 
*/
#include<iostream>
#include<vector>

using namespace std;

int bestRotation(vector<int>& nums) {
    int n = nums.size();
    vector<int> diff(n + 1);
    for(int i = 0; i < n; i++) {
        if(i >= nums[i]) {
            diff[0]++;
            diff[i - nums[i] + 1]--;
            diff[i + 1]++;
        } else {
            diff[i + 1]++;
            diff[i - nums[i] + n + 1]--;
        }
    }
    int ans = 0, cur = 0, max = 0;
    for(int i = 0; i < n; i++) {
        cur += diff[i];
        if(cur > max) {
            ans = i;
            max = cur;
        }
    }
    return ans;
}