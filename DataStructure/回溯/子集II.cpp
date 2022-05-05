/*
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。。
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int>>ans;
void backtrack(vector<int>& nums, vector<int>& path, int s){
    ans.emplace_back(path);

    for(int i=s; i<nums.size(); i++){
        // 注意 这里 i>s 不是 i>0
        if(i>s&&nums[i]==nums[i-1]){
            continue;
        }
        path.emplace_back(nums[i]);
        backtrack(nums, path, i+1);
        path.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<int>path;
    sort(nums.begin(), nums.end());
    backtrack(nums, path, 0);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,2};
    vector<vector<int>>ans = subsetsWithDup(nums);
    for(auto&nn: ans){
        for(auto&n: nn){
            cout<<n<<", ";
        }
        cout<<endl;
    }
    return 0;
}
