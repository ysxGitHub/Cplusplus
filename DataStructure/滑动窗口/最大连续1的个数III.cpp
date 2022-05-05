/*
给定一个二进制数组 nums 和一个整数 k ，如果可以翻转最多k 个 0 ，则返回 数组中连续 1 的最大个数 。
*/

#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int start=0, maxLen=0, cntOne=0;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i]) cntOne++;
        maxLen = max(maxLen, cntOne);
        if(i - start + 1 > maxLen + k){
            if(nums[start]) cntOne--;
            start++;
        }
    }
    return n - start;
}

// 二分法
int longestOnes1(vector<int>& nums, int k) {
    int n = nums.size();
    vector<int> P(n + 1);
    for (int i = 1; i <= n; ++i) {
        P[i] = P[i - 1] + (1 - nums[i - 1]);
    }

    int ans = 0;
    for (int right = 0; right < n; ++right) {
        int left = lower_bound(P.begin(), P.end(), P[right + 1] - k) - P.begin();
        ans = max(ans, right - left + 1);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

