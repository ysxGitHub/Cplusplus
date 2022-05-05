/*
给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。
*/

#include<vector>
#include<iostream>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();
    vector<vector<int>>dp(m+1, vector<int>(n+1,0));
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(word1[i]==word2[j]){
                dp[i+1][j+1] = dp[i][j] + 1;
            }else{
                dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
    }
    return m + n - 2*dp[m][n];
}



int main(int argc, char const *argv[])
{
    
    return 0;
}
