/*
给定一个整数数组  nums 和一个正整数 k，找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。

473.火柴拼正方形
*/
#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

// 从桶的角度出发
bool backtrace(vector<int>& nums, vector<bool>used, int target, int start, int bucket, int k){
    // 所以的桶都填满, 且符合要求
    if(k==0){return 1;}
    // 当前的桶到达要求
    if(bucket==target){
        return backtrace(nums, used, target, 0, 0, k-1);
    }
    for(int i=start; i<nums.size(); i++){
        if(used[i] || nums[i]+bucket > target){
            continue;
        }
        used[i] = 1;
        bucket += nums[i];
        if(backtrace(nums, used, target, i+1, bucket, k)){
            return 1;
        }
        used[i] = 0;
        bucket -= nums[i];
        // 这句话非常重要, 说明当前的桶没有能满足要求
        if(bucket == 0){return 0;}
    }
    return 0;
}


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = 0, maxN = -1;
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i=0; i<n; i++){
        sum += nums[i];
        if(maxN<nums[i]) maxN = nums[i];
    }
    int avg = sum/k;
    if(avg * k < sum || maxN > avg || k > n){return 0;}
    vector<bool>seen(n, 0);
    return backtrace(nums, seen, avg, 0, 0, k);
}

int main(int argc, char const *argv[])
{

    return 0;
}
