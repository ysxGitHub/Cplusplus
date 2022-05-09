/*
由范围 [0,n] 内所有整数组成的 n + 1 个整数的排列序列可以表示为长度为 n 的字符串 s ，其中:

如果 perm[i] < perm[i + 1] ，那么 s[i] == 'I' 
如果 perm[i] > perm[i + 1] ，那么 s[i] == 'D' 
给定一个字符串 s ，重构排列 perm 并返回它。如果有多个有效排列perm，则返回其中 任何一个 。
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> diStringMatch(string s) {
    int n = s.size();
    vector<int>ans;
    int left=0, right=n;
    for(auto&c: s){
        if(c=='I'){
            ans.push_back(left++);
        }else{
            ans.push_back(right--);
        }
    }
    ans.push_back(right);
    return ans;
}