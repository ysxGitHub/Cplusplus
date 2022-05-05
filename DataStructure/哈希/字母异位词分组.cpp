/*
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的字母得到的一个新单词，所有源单词中的字母通常恰好只用一次。
*/
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

string encoder(string& s){
    string ans(26, '0');
    for(int i=0; i<s.size(); i++){
        int idx = s[i] - 'a';
        ans[idx]++;
    }
    return ans;
}
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>>cnt;
    vector<vector<string>> ans;
    for(auto&s: strs){
        string code = encoder(s);
        cnt[code].push_back(s);
    }
    for(auto&it: cnt){
        ans.push_back(it.second);
    }
    return ans;
}

