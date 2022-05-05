/*
给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

回文串 是正着读和反着读都一样的字符串。
*/
#include<vector>
#include<iostream>
using namespace std;


// 方法1 回溯
bool isPalindrome(string& s){
    if(s.size()==1) return 1;
    int num=0, n=s.size();
    if(n%2){
        int l=n/2-1, r=n/2+1;
        while(l>=0&&r<n&&s[l--]==s[r++]) num++;
        if(num==n/2) return 1;
        else return 0;
    }else{
        int l=n/2-1, r=n/2;
        while(l>=0&&r<n&&s[l--]==s[r++]) num++;
        if(num==n/2) return 1;
        else return 0;
    }
}

vector<vector<string>> ans;
void backtrace(string&s, vector<string>&path, int idx, int n, int cnt){
    if(idx>=n&&cnt==n){
        ans.push_back(path);
        return ;
    }
    for(int j=idx; j<n; j++){
        for(int i=1; i+j<=n; i++){
            string ssub = s.substr(j,i);
            if(!isPalindrome(ssub)) continue;
            cnt+=i;
            path.push_back(ssub);
            backtrace(s, path, j+i, n, cnt);
            cnt-=i;
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> path;
    int n = s.size();
    backtrace(s, path, 0, n, 0);
    return ans;
}


//方法2动态规划+回溯
vector<vector<string>> ans;
void backtrace(string&s, vector<string>&path, vector<vector<bool>>&dp, int idx, int n){
    if(idx>=n){
        ans.push_back(path);
        return ;
    }
    for(int i=idx; i<n; i++){
        if(dp[idx][i]){
            path.push_back(s.substr(idx, i-idx+1));
            backtrace(s, path, dp, i+1, n);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> path;
    int n = s.size();
    // dp[i][j] 表示 i 到 j 是不是 回文子串
    vector<vector<bool>>dp(n, vector<bool>(n));
    for(int right=0; right<n; right++){
        for(int left=0; left<=right; left++){
            if(s[left]==s[right]&&(right-left<=2||dp[left+1][right-1])){
                dp[left][right]=1;
            }
        }
    }
    backtrace(s, path, dp, 0, n);
    return ans;
}


