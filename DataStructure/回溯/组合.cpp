/*
给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。

你可以按 任何顺序 返回答案。
*/
#include<iostream>
#include<vector>
using namespace std;


void backtrack(int n, int k, int front, vector<vector<int>>&ans, vector<int>&res){
    if(res.size()==k){
        ans.emplace_back(res);
        return;
    }
    for(int i=front; i<=n; i++){
        res.emplace_back(i);
        backtrack(n, k, i+1, ans, res);
        res.pop_back();
    }

}
vector<vector<int>> combine(int n, int k) {
    vector<vector<int>>ans;
    vector<int>res;
    backtrack(n, k, 1, ans, res);
    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>>ans = combine(4,3);
    for(auto&n: ans){
        for(auto&m: n){
            cout<<m<<" ";
        }
        cout<<endl;
    }    
    return 0;
}