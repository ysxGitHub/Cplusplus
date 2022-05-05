/*
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
*/

#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>>ans;

void backtrace(vector<int>& nums, vector<int>&path, int s){
    ans.emplace_back(path);
    for(int i=s; i<nums.size(); i++){
        path.emplace_back(nums[i]);
        backtrace(nums, path, i+1);
        path.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums) {
    vector<int>path;
    backtrace(nums, path, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
