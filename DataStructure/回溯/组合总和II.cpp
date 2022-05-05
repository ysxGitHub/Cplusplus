/*
给定一个候选人编号的集合 candidates 和一个目标数 target ，
    找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用 一次 。

注意：解集不能包含重复的组合。 
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtarck(vector<int>& candidates, int target, int begin, vector<int>&path, vector<vector<int>>&ans){
    if(target==0){
        ans.emplace_back(path);
        return;
    }
    // 注意这里的i从begin开始，不能从0开始，前面使用过的不再使用
    for(int i=begin; i<candidates.size(); i++){
        // 同一层相同数值的结点，因此跳过，用 continue
        if(target-candidates[i]<0||(i>begin&&candidates[i-1]==candidates[i])){
            continue;
        }
        path.emplace_back(candidates[i]);
        // 不能包含同一个位置上的元素
        backtarck(candidates, target-candidates[i], i+1, path, ans);
        path.pop_back();
    }

}


vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<int>path;
    vector<vector<int>>ans;
    sort(candidates.begin(), candidates.end(), less<int>());
    backtarck(candidates, target, 0, path, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<int>candidates={10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>>ans = combinationSum2(candidates, target);
    for(auto&n: ans){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }    
    return 0;
}