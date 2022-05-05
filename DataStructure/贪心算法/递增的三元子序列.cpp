/*
给你一个整数数组 nums ，判断这个数组中是否存在长度为 3 的递增子序列。

如果存在这样的三元组下标 (i, j, k) 且满足 i < j < k ，使得 nums[i] < nums[j] < nums[k] ，
    返回 true ；否则，返回 false 。
*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

bool increasingTriplet(vector<int>& nums) {
    int n = nums.size();
    vector<int>left_min(n, INT32_MAX);
    vector<int>right_max(n, INT32_MIN);
    left_min[0] = nums[0];
    right_max[n-1] = nums[n-1];
    for(int i=1; i<n; i++){
        left_min[i] = min(left_min[i-1], nums[n-1]);
    }
    for(int i=n-2; i>=0; i--){
        right_max[i] = max(right_max[i+1], nums[i+1]);
    }
    for(int i=0; i<n; i++){
        if(left_min[i]<nums[i]&&nums[i]<right_max[i]){
            return 1;
        }
    }
    return 0;
}

// 贪心
bool increasingTriplet2(vector<int>& nums) {
    int n = nums.size();
    if(n<3){
        return 0;
    }     
    int first = nums[0], second = INT_MAX;
    for(int i=1; i<n; i++){
        int num = nums[i];
        // 存在大于第二个数的元素
        if(num>second){
            return 1;
        }
        // 当大于第一个数时
        else if(num>first){
            second = num;
        }else{
            first = num;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
