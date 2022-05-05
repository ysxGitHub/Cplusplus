/*
给你一个字符串数组 words ，找出并返回 length(words[i]) * length(words[j]) 的最大值，
    并且这两个单词不含有公共字母。如果不存在这样的两个单词，返回 0 。
*/
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;


int maxProduct(vector<string>& words) {
    int n = words.size();
    unordered_map<int, int>masks;
    for(string s: words){
        int num = 0;
        int len = s.size();
        for(char c: s){
            int u = c - 'a';
            num |= (1<<u);
        }
        if(!masks.count(num)||masks[num]<len){
            masks[num] = len;
        }
    }
    int ans = 0;
    for(auto a: masks){
        for(auto b: masks){
            if((a.first&b.first)==0&&a.second*b.second>ans){
                ans = a.second*b.second;
            }
        }
    }        
    return ans;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}
