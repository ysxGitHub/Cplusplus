/*
给你一个整数数组 nums 和一个整数 k ，找出 nums 中和至少为 k 的 最短非空子数组 ，
    并返回该子数组的长度。如果不存在这样的 子数组 ，返回 -1 。

子数组 是数组中 连续 的一部分。
*/
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int>dq;
    vector<long long>sumArr(n+1);
    sumArr[0] = 0;
    int ans = 10000000;
    // 求前缀和
    for(int i=1; i<=n; i++){
        sumArr[i] = nums[i-1] + sumArr[i-1];
        // cout<<sumArr[i]<<endl;
    }
    // 注意这里是 n+1 不是 n，遍历的是前缀和
    for(int i=0; i<n+1; i++){
        // 如果 0~i 的和还比 0~i+1 的和，还要大，证明 i+1 为负数，可以将前面 0~i 的和弹出
        while(!dq.empty()&&sumArr[dq.back()]>=sumArr[i]){
            dq.pop_back();
        }
        // 如果 0~i+1 的和大于等于 0~i 的和 + k，则可以记录下来，并进行弹出
        while(!dq.empty()&&sumArr[i]-sumArr[dq.front()]>=k){
            ans = min(ans, i - dq.front());
            dq.pop_front();
        }
        dq.emplace_back(i);
    }
    return ans==10000000 ? -1 : ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {56,-21,56,35,-9};
    cout<<shortestSubarray(nums, 61)<<endl;
    return 0;
}
