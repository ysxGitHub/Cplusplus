/*
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。

你可以对一个单词进行如下三种操作：

插入一个字符
删除一个字符
替换一个字符
*/

#include<iostream>
#include<vector>
using namespace std;


int minDistance(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));

    for(int i=1; i<=m; i++){
        dp[i][0] = i;
    }

    for(int j=1; j<=n; j++){
        dp[0][j] = j;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(word1[i-1]==word2[j-1]){
                // 如果前面的字符相等直接跳过，本次 dp 直接等于上次的 dp
                dp[i][j] = dp[i-1][j-1];
            }else{
                // dp[i-1][j-1] 表示替换 i 和 j 同时要前移
                // dp[i][j-1] 表示插入 j 要前移
                // dp[i-1][j] 表示删除 i 要前移
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
            }
        }
    }
    return dp[m][n];
}


// 具体的操作是什么？
struct Node{
    int val = 0;
    int choice = -1;
    // 0  跳过
    // 1  替换
    // 2  插入
    // 3  删除
};

int minDistance1(string word1, string word2) {
    int m = word1.size(), n = word2.size();

    vector<vector<Node>>dp(m+1, vector<Node>(n+1));
    
    for(int i=1; i<=m; i++){
        dp[i][0].val = i;
    }

    for(int j=1; j<=n; j++){
        dp[0][j].val = j;
    }

    for(int i=1; i<=m; i++){
        for(int j=1; j<=n; j++){
            if(word1[i-1]==word2[j-1]){
                // 如果前面的字符相等直接跳过，本次 dp 直接等于上次的 dp
                dp[i][j].val = dp[i-1][j-1].val;
                dp[i][j].choice = 0;
            }else{
                // dp[i-1][j-1] 表示替换 i 和 j 同时要前移
                // dp[i][j-1] 表示插入 j 要前移
                // dp[i-1][j] 表示删除 i 要前移
                dp[i][j].val = dp[i-1][j-1].val + 1;
                dp[i][j].choice = 1;

                if(dp[i][j].val>dp[i][j-1].val + 1){
                    dp[i][j].val = dp[i][j-1].val + 1;
                    dp[i][j].choice = 2;
                }

                if(dp[i][j].val>dp[i-1][j].val + 1){
                    dp[i][j].val = dp[i-1][j].val + 1;
                    dp[i][j].choice = 3;
                }                
            }
        }
    }
    return dp[m][n].val;
}



int main(int argc, char const *argv[])
{
    cout<<minDistance("horse", "ros");
    return 0;
}
