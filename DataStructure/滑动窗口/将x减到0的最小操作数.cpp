/*
给你一个整数数组 nums 和一个整数 x 。每一次操作时，你应当移除数组 nums 最左边或最右边的元素，然后从 x 中减去该元素的值。请注意，需要 修改 数组以供接下来的操作使用。

如果可以将 x 恰好 减到 0 ，返回 最小操作数 ；否则，返回 -1 。
*/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<numeric>
using namespace std;

// 前缀和
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int target = accumulate(nums.begin(), nums.end(), 0) - x;
    if(target==0) return n;
    unordered_map<int, int>preSum;
    preSum[0]=-1;
    int res=-1;
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=nums[i];
        if(preSum.count(sum-target)){
            res = max(res, i-preSum[sum-target]);
        }
        preSum[sum] = i;
    }
    return res==-1?-1:n-res;
}

// 滑动窗口
int minOperations(vector<int>& nums, int x) {
    int n = nums.size();
    int target = accumulate(nums.begin(), nums.end(), 0) - x;
    if(target==0) return n;
    if(target<0) return -1;

    int left = 0, right = 0;
    int ans = -1;        //最长连续数组【和为target】
    int cnt = 0;         //滑动窗口中的数字总和
    while(right<n){
        cnt += nums[right];
        while(cnt>target){
            cnt -= nums[left];
            left += 1;
        }
        if(cnt == target){
            ans = max(ans, right-left+1);
        }
        right += 1;
    }
    return ans==-1?-1:n-ans;
}