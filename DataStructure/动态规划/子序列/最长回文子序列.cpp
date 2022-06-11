/*
给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。

*/
#include<vector>
#include<iostream>
using namespace std;

/*
dp 数组的定义是：在子串s[i..j]中，最长回文子序列的长度为dp[i][j]。
    i i+1         j-1 j
    ?  b  x  a  b  y  ?
    dp[i+1][j-1] = 3;
    if(s[i]==s[j])  dp[i][j] = dp[i+1][j-1] + 2
    else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
*/
int longestPalindromeSubseq(string s) {
    int n = s.size();
    vector<vector<int>>dp(n, vector<int>(n,0));
    for(int i=0; i<n; i++){
        dp[i][i] = 1;
    }
    for(int i=n-1; i>=0; i--){
        for(int j=i+1; j<n; j++){
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1] + 2;
                // printf("dp[%d][%d]=dp[%d][%d]+2=%d\n",i,j,i+1,j-1,dp[i+1][j-1]+2);
            }else{
                dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                // printf("dp[%d][%d]=max(dp[%d][%d], dp[%d][%d]) = max(%d, %d) = %d\n",i,j,i+1,j,i,j-1,dp[i+1][j],dp[i][j-1],max(dp[i+1][j], dp[i][j-1]));
            }
        }
    }
    return dp[0][n-1];
}

int main(int argc, char const *argv[])
{
    longestPalindromeSubseq("bbbab");
    return 0;
}
