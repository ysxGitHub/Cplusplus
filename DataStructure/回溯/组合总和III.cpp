/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，
    并且每种组合中不存在重复的数字。

说明：
    所有数字都是正整数。
    解集不能包含重复的组合。 
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void backtrack(int k, int n, int first, vector<int>&path, vector<vector<int>>&ans){
    if(path.size()==k&&n==0){
        ans.emplace_back(path);
        return;
    }
    for(int i=first; i<=min(n, 9); i++){  
        if(n-i<0){
            continue;
        }
        path.emplace_back(i);
        backtrack(k, n-i, i+1, path, ans);
        path.pop_back();
    }

}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<int>path;
    vector<vector<int>>ans;
    backtrack(k, n, 1, path, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>>ans = combinationSum3(3,7);
    for(auto&n: ans){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }    
    return 0;
}