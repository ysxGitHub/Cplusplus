/*
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。

请你找出并返回 strs 的最大子集的长度，该子集中 最多 有 m 个 0 和 n 个 1 。

如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。
*/

#include<vector>
#include<iostream>
using namespace std;

pair<int, int>get01(string s){
    int a=0, b=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='0'){
            a++;
        }else{
            b++;
        }
    }
    return make_pair(a, b);
}

int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>>dp(m+1, vector<int>(n+1, 0));
    for(string s : strs){
        auto num = get01(s);
        int zero = num.first, one = num.second;
        for(int i=m; i>=zero; i--){
            for(int j=n; j>=one; j--){
                dp[i][j] = max(dp[i][j], dp[i-zero][j-one] + 1); 
            }
        }
    }
    return dp[m][n];
}

int main(int argc, char const *argv[])
{
    vector<string> strs={"10", "0001", "111001", "1", "0"};
    cout<<findMaxForm(strs, 5, 3);
    return 0;
}
