/*
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void backtrack(vector<int>& nums, vector<int>&path, vector<bool>&seen, vector<vector<int>>&ans, int len){
    if(path.size()==len){
        ans.emplace_back(path);
        return;
    }
    for(int i=0; i<len; i++){
        // 判断是否已经遍历过相同的元素
        if(seen[i]||(i>0&&nums[i-1]==nums[i]&&!seen[i-1])){
            // 如果前面的相邻相等元素没有用过，则跳过
            continue;
        }
        seen[i] = true;
        path.emplace_back(nums[i]);
        backtrack(nums, path, seen, ans, len);
        path.pop_back();
        seen[i] = false;
    }
}
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>>ans;
    vector<int>path;
    vector<bool>seen(nums.size(), 0);
    // 先排序
    sort(nums.begin(), nums.end());
    // 在进行回溯
    backtrack(nums, path, seen, ans, nums.size());
    return ans;
}
int main(int argc, char const *argv[])
{
    vector<int> nums={2,1,2};
    vector<vector<int>>ans = permuteUnique(nums);
    for(auto&n: ans){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}
