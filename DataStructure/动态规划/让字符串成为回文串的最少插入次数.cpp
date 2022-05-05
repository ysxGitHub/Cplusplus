/*
给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。

请你返回让 s 成为回文串的 最少操作次数 。

「回文串」是正读和反读都相同的字符串。
*/

#include<vector>
#include<iostream>

using namespace std;

int minInsertions(string s) {
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n));
    // dp[i][j] 表示 s[i...j] 为回文所需最少操作
    // dp[i][j] 可由 dp[i+1][j-1] , dp[i+1][j], dp[i][j-1] 推出
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                // 字符相等不需要填充
                dp[i][j] = dp[i+1][j-1];
            }else{
                // 如果 [i+1...j] 或 [i...j-1] 为回文时, 只需在添加一个就是回文
                dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
            }
        }
    }
    // s[0...n-1] 最少的操作
    return dp[0][n-1];
}

// 利用最长回文子序列
int minInsertions1(string s) {
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n));
    for(int i=0; i<n; i++) dp[i][i]=1;
    // dp[i][j] 表示 s[i...j] 为回文所需最少操作
    // dp[i][j] 可由 dp[i+1][j-1] , dp[i+1][j], dp[i][j-1] 推出
    for(int i=n-2; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
            }
        }
    }
    return n - dp[0][n-1];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
