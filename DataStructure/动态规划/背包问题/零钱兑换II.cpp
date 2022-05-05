/*
给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。

请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。

假设每一种面额的硬币有无限个。 

题目数据保证结果符合 32 位带符号整数。

*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;


// 组合问题，且不考虑顺序
int change(int amount, vector<int>& coins) {
    vector<int>dp(amount+1, 0);
    dp[0] = 1;
    for(auto&c: coins){
        for(int i=c; i<amount+1; i++){
            dp[i] += dp[i-c];
        }
    }
    return dp[amount];
}

int main(int argc, char const *argv[])
{
    int amount = 6; 
    vector<int> coins = {1,2,3};
    cout<<change(amount, coins);
    return 0;
}
