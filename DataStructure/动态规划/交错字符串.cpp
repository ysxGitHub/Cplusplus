/*
给定三个字符串 s1、s2、s3，请你帮忙验证 s3 是否是由 s1 和 s2 交错 组成的。

两个字符串 s 和 t 交错 的定义与过程如下，其中每个字符串都会被分割成若干 非空 子字符串：

s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
交错 是 s1 + t1 + s2 + t2 + s3 + t3 + ...
    或者 t1 + s1 + t2 + s2 + t3 + s3 + ...
注意：a + b 意味着字符串 a 和 b 连接。
*/
#include<vector>
#include<iostream>
using namespace std;

/*
我们使用 dp[i][j] 表示 s1 的前 i 个字符和 s2 的前 j 个字符是否能构成 s3 的前 i+j 个字符。

首先，dp[0][0] 一定是 True 初始化 s1,s2,s3 的长度分别为 len1,len2,len3

若 len1+len2!=len3，表示一定不能构成交错字符串，返回 False

初始化 dp 为 (len1+1)*(len2+1) 的 False 数组。

初始化第一列 dp[i][0]，遍历第一列，遍历区间 [1,len1+1)：
dp[i][0]=dp[i−1][0] and s1[i−1]==s3[i−1]。表示 s1 的前 i 位是否能构成 s3 的前 i 位。
    因此需要满足的条件为，前 i-1 位可以构成 s3 的前 i-1 位且 s1 的第 i 位（s1[i-1]）
    等于 s3 的第 i 位（s3[i-1]）

初始化第一行 dp[0][j]，遍历第一行，遍历区间 [1,len2+1)：
dp[0][i]=dp[0][i-1] and s2[i-1]==s3[i-1]。表示 s2 的前 i 位是否能构成 s3 的前 i 位。
    因此需要满足的条件为，前 i-1 位可以构成 s3 的前 i-1 位且 s2 的第 i 位（s2[i-1]）
    等于 s3 的第 i 位（s3[i-1]）

遍历 dp 数组，每一行 i，遍历区间 [1,len1+1)：
每一列 j，遍历区间 [1,len2+1)：
dp[i][j] = (dp[i-1][j]&(s1[i-1]==s3[i+j-1]))|(dp[i][j-1]&(s2[j-1]==s3[i+j-1]));
    解释：s1 前 i 位和 s2 的前 j 位能否组成 s3 的前 i+j 位取决于两种情况：

s1 的前 i 个字符和 s2 的前 j-1 个字符能否构成 s3 的前 i+j-1 位，
    且 s2 的第 j 位（s2[j-1]）是否等于 s3 的第 i+j 位（s3[i+j-1]）。

返回 dp[m][n]
*/

bool isInterleave(string s1, string s2, string s3) {
    int size1 = s1.size(), size2 = s2.size(), size = s3.size();
    if(size1 + size2 != size) return false;
    vector<vector<bool>>dp(size1+1, vector<bool>(size2+1));
    dp[0][0] = true;

    for(int i=1; i<=size1; i++){
        dp[i][0] = dp[i-1][0]&(s1[i-1]==s3[i-1]);
    }
    for(int j=1; j<=size2; j++){
        dp[0][j] = dp[0][j-1]&(s2[j-1]==s3[j-1]);
    }
    for(int i=1; i<=size1; i++){
        for(int j=1; j<=size2; j++){
            dp[i][j] = (dp[i-1][j]&(s1[i-1]==s3[i+j-1]))|(dp[i][j-1]&(s2[j-1]==s3[i+j-1]));
        }
    }

    return dp[size1][size2];
}