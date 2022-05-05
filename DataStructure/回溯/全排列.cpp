/*
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/
#include<iostream>
#include<vector>
// #include<unordered_set>

using namespace std;
// 
void backtrack(vector<int>& nums, vector<vector<int>>&res, int first, int len){
    if(first==len){
        res.emplace_back(nums);
        return;
    }
    for(int i=first; i<len; i++){
        swap(nums[first], nums[i]);
        backtrack(nums, res, first+1, len);
        swap(nums[first], nums[i]);
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>>res;
    backtrack(nums, res, 0, nums.size());
    return res;
}

void backtrack1(vector<int>&nums, vector<int>&path, vector<bool>&used, vector<vector<int>>&ans){
    if(path.size()==nums.size()){
        ans.emplace_back(path);
        return ;
    }

    for(int i=0; i<nums.size(); i++){
        if(used[i]==true){continue;}
        path.emplace_back(nums[i]);
        used[i] = true;
        backtrack1(nums, path, used, ans);
        // 回溯
        path.pop_back();
        used[i] = false;
    }
}

vector<vector<int>> permute1(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int>path;
    vector<bool>used(nums.size(), 0);
    backtrack1(nums, path, used, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums = {1,2,3};
    vector<vector<int>>res = permute1(nums);
    for(auto&n: res){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}

