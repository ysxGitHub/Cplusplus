/*
给定一个可能含有重复元素的整数数组，要求随机输出给定的数字的索引。
     您可以假设给定的数字一定存在于数组中。

注意：
数组大小可能非常大。 使用太多额外空间的解决方案将不会通过测试。

*/
#include<iostream>
#include<vector>

using namespace std;



class Solution {
public:
    vector<int>nums;
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int cnt = 0, res = -1;  
        for(int i=0; i<nums.size(); i++){
            if(nums[i]!=target) continue;
            cnt++;
            if(rand()%cnt==0) res = i;
        }
        return res;
    }
};