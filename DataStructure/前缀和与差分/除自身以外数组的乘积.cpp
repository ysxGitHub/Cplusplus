/*
给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。

题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。

请不要使用除法，且在 O(n) 时间复杂度内完成此题。

*/
#include <vector>
using namespace std;

/*
nums = 1 2 3 4
l =    1 1 2 6
r =    1 4 12 24
ans =  1        1
       1  1  4  1
       1  12 8  1
       24 12 8  6
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    int left=1, right=1; //left：从左边累乘，right：从右边累乘
    vector<int>res(n,1);
    for(int i=0; i<n; i++){ //最终每个元素其左右乘积进行相乘得出结果
        res[i]*=left;  //乘以其左边的乘积
        left*=nums[i];
        res[n-i-1]*=right;   //乘以其右边的乘积
        right*=nums[n-i-1];
    }
    return res;
}