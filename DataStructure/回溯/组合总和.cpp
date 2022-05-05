/*
给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
    找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。
    你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，
    则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

void backtarck(vector<int>& candidates, int target, int begin, vector<int>&path, vector<vector<int>>&ans){
    if(target==0){
        ans.emplace_back(path);
        return;
    }
    // 注意这里的i从begin开始，不能从0开始，前面使用过的不再使用
    for(int i=begin; i<candidates.size(); i++){
        if(target-candidates[i]<0){
            continue;
        }
        path.emplace_back(candidates[i]);
        // 但是下一层还可以使用本元素所有begin从i开始
        backtarck(candidates, target-candidates[i], i, path, ans);
        path.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<int>path;
    vector<vector<int>>ans;
    // sort(candidates.begin(), candidates.end(), greater<int>());
    backtarck(candidates, target, 0, path, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>candidates={2,3,1};
    int target = 6;
    //[[1,1,1,1,1,1],[1,1,1,1,2],[1,1,1,3],[1,1,2,2],[1,2,3],[2,2,2],[3,3]]
    vector<vector<int>>ans = combinationSum(candidates, target);
    for(auto&n: ans){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }    
    return 0;
}
