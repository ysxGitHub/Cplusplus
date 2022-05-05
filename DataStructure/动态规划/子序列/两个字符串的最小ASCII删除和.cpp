/*
给定两个字符串s1 和 s2，返回 使两个字符串相等所需删除字符的 ASCII 值的最小和 。
*/
#include<vector>
#include<iostream>

using namespace std;


int minimumDeleteSum(string s1, string s2) {
    int m = s1.size(), n = s2.size();
    int sumall = 0;
    vector<vector<int>>dp(m+1, vector<int>(n+1));

    for(auto s: s1) sumall += (int)s;
    for(auto s: s2) sumall += (int)s;  

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(s1[i]==s2[j]){
                dp[i+1][j+1] = dp[i][j] + (int)s1[i];
            }else{
                dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }
    return sumall - 2*dp[m][n];
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
