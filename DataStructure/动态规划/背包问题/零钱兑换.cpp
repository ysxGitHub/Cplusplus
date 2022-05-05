/*
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

*/
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
#include<unordered_map>
using namespace std;

unordered_map<int, int>memo;
int dp(vector<int>& coins, int amount){
    if(amount<0){
        return -1;
    }
    if(amount==0){
        return 0;
    }
    if(memo[amount]!=0){
        return memo[amount];
    }
    int res = INT32_MAX;
    for(auto&coin: coins){
        int subres = dp(coins, amount-coin);
        if(subres==-1){
            continue;
        }
        else{
            res = min(res, 1+subres);
        }
    }
    memo[amount] = (res == INT32_MAX) ? -1 : res;
    return memo[amount];
}

int coinChange(vector<int>& coins, int amount) {
    return dp(coins, amount);
}

// 完全背包
int coinChange1(vector<int>& coins, int amount) {
    vector<int>nums(amount+1, amount+1);
    nums[0] = 0;
    for(auto&coin : coins){
        for(int i=coin; i<=amount; i++){
               nums[i] = min(nums[i], nums[i-coin]+1);
       } 
    }
    return (nums[amount]>amount ? -1 : nums[amount]);
}


int main(int argc, char const *argv[])
{
    vector<int>coins = {186,419,83,408};
    cout<<coinChange1(coins, 6249)<<endl;
    return 0;
}
