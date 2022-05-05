/*
给你一个字符串 s 和一个字符串列表 wordDict 作为字典。请你判断是否可以利用字典中出现的单词拼接出 s 。

注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。
*/

#include<vector>
#include<iostream>
using namespace std;

// 
bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.size();
    vector<bool>dp(n+1);
    dp[0] = 1;
    for(int i=0; i<=n; i++){
        for(string w : wordDict){
            int len = w.size();
            if(i>=len && s.substr(i-len, len)==w){
                dp[i] = dp[i]||dp[i-len];
            }
        }
    }
    return dp[n];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
