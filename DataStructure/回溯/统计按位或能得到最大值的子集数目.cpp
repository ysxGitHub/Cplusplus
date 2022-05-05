/*
给你一个整数数组 nums ，请你找出 nums 子集 按位或 可能得到的 最大值 ，并返回按位或能得到最大值的 
    不同非空子集的数目 。

如果数组 a 可以由数组 b 删除一些元素（或不删除）得到，则认为数组 a 是数组 b 的一个 子集 。
    如果选中的元素下标位置不一样，则认为两个子集 不同 。

对数组 a 执行 按位或 ，结果等于 a[0] OR a[1] OR ... OR a[a.length - 1]（下标从 0 开始）。

*/
#include<vector>
#include<iostream>
using namespace std;

void dfs(vector<int>& nums, vector<int>& path, int s, int maxNum, int& ans){
    for(int i=s; i<nums.size(); i++){
        path.push_back(nums[i]);
        int tmp=0;
        for(int j=0; j<path.size(); j++) tmp |= path[j];
        if(tmp==maxNum) ans++;
        dfs(nums, path, i+1, maxNum, ans);
        path.pop_back();
    }
}
int countMaxOrSubsets(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    vector<int> path;
    int maxNum = 0;
    for(int i=0; i<n; i++) maxNum |= nums[i];
    dfs(nums, path, 0, maxNum, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int> nums={1,1,2};
    cout<<countMaxOrSubsets(nums);
    return 0;
}
