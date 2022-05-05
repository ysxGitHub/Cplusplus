/*
给你一个整数数组 nums 和一个正整数 k，请你判断是否可以把这个数组划分成一些由 k 
    个连续数字组成的集合。
如果可以，请返回 true；否则，返回 false。
*/
#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

bool isPossibleDivide(vector<int>& nums, int k) {
    int n = nums.size();
    if (n % k != 0) {
        return false;
    }
    sort(nums.begin(), nums.end());
    unordered_map<int, int> cnt;
    for (auto & num : nums) {
        cnt[num]++;
    }
    for (auto & x : nums) {
        if (!cnt.count(x)) {
            continue;
        }
        for (int j = 0; j < k; j++) {
            int num = x + j;
            if (!cnt.count(num)) {
                return false;
            }
            cnt[num]--;
            if (cnt[num] == 0) {
                cnt.erase(num);
            }
        }
    }
    return true;
}