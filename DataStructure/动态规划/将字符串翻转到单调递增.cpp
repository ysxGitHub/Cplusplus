/*
如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。
*/
#include <string>
#include <vector>
using namespace std;

//
int minFlipsMonoIncr(const string& s) {
    int n = s.size();
    // 用 dp[i][0] 和 dp[i][1] 分别表示下标 i 处的字符为 0 和 1 的情况下使得 s[0..i] 单调递增的最小翻转次数。
    vector<pair<int, int>>dp(n);
    dp[0].first = s[0]=='1'?1:0;
    dp[0].second = s[0]=='0'?1:0;
    for(int i=1; i<n; ++i){
        // 如果下标 i 处的字符是 0，则只有当下标 i - 1 处的字符是 0 时才符合单调递增；
        dp[i].first = dp[i-1].first;
        // 如果下标 i 处的字符是 1，则当下标 i - 1 处的字符是 0/1 都符合单调递增；
        dp[i].second = min(dp[i-1].first, dp[i-1].second);
        if(s[i]=='0'){
            ++dp[i].second; // s[i] == '0'  dp[i][1]++
        }else{
            ++dp[i].first; // s[i] == '1'  dp[i][0]++
        }
    }
    return min(dp[n-1].first, dp[n-1].second);
}

// 状态压缩
int minFlipsMonoIncr(const string& s) {
    int dp0 = 0, dp1 = 0;
    for(auto&c: s){
        int dp0new = dp0, dp1new = min(dp0, dp1);
        if(c=='0'){
            ++dp1new;
        }else{
            ++dp0new;
        }
        dp0 = dp0new, dp1 = dp1new;
    }
    return min(dp0, dp1);
}