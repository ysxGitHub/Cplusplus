/*
给你一个整数数组 nums ，请你找出数组中乘积最大的非空连续子数组（该子数组中至少包含一个数字），
    并返回该子数组所对应的乘积。

测试用例的答案是一个 32-位 整数。

子数组 是数组的连续子序列。
*/
#include<iostream>
#include<vector>
using namespace std;

/*
思路三：根据符号的个数 [^2]
当负数个数为偶数时候，全部相乘一定最大
当负数个数为奇数时候，它的左右两边的负数个数一定为偶数，只需求两边最大值
当有 0 情况，重置就可以了
*/
int maxProduct(vector<int>& nums) {
    int n = nums.size();
    vector<int>rnums(nums.rbegin(), nums.rend());
    for(int i=1; i<n; i++){
        if(nums[i-1]!=0) nums[i] *= nums[i-1];
        else nums[i] *= 1;
        if(rnums[i-1]!=0) rnums[i] *= rnums[i-1];
        else rnums[i] *=1;
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        if(nums[i]>ans)  ans = nums[i];
        if(rnums[i]>ans)  ans = rnums[i];
    }
    return ans;
}
/*
思路二：动态规划 [^1]
我们需要维护两个变量，当前的最大值，以及最小值，最小值可能为负数，但没准下一步乘以一个负数，
    当前的最大值就变成最小值，而最小值则变成最大值了。
*/

int maxProduct1(vector<int>& nums){
    int n = nums.size();
    int res = nums[0], pre_max = nums[0], pre_min = nums[0];
    for(int i=1; i<n; i++){
        int cur_max = max(max(pre_max * nums[i], pre_min * nums[i]), nums[i]);
        int cur_min = min(max(pre_max * nums[i], pre_min * nums[i]), nums[i]);
        res = max(res, cur_max);
        pre_max = cur_max;
        pre_min = cur_min;
    }
    return res;
}