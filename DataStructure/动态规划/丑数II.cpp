/*
给你一个整数 n ，请你找出并返回第 n 个 丑数 。
丑数 就是只包含质因数 2、3 和/或 5 的正整数。
*/

#include<queue>
#include<unordered_set>
#include<iostream>
#include<vector>

using namespace std;

// 法1：优先队列；思想：先选择，再排序
int nthUglyNumber1(int n) {
    unordered_set<long long> seen;
    priority_queue<long long, vector<long long>, greater<long long>>pq;
    pq.emplace(1);
    long long ans = 1L;
    for(int i=0; i<n; i++){
        ans = pq.top();
        for(int c: {2,3,5}){
            long long tmp = (long long)ans * c;
            if(tmp>INT32_MAX){continue; }
            if(seen.find(tmp)==seen.end()){
                pq.emplace(tmp);
                seen.insert(tmp);
            } 
        }
        pq.pop();
    }
    return ans;
}

// 法2：dp , 思想：先排序，再选择
int nthUglyNumber(int n) {
    vector<int>dp(n+1);
    // base case
    dp[1] = 1;
    int p2 = 1, p3 = 1, p5 = 1;
    for(int i=2; i<=n; i++){
        int num2 = dp[p2]*2, num3 = dp[p3]*3, num5 = dp[p5]*5; 
        dp[i] = min(min(num2, num3), num5);
        if(dp[i]==num2){
            ++p2;
        }
        if(dp[i]==num3){
            ++p3;
        }
        if(dp[i]==num5){
            ++p5;
        }        
    }
    return dp[n];
}



int main(int argc, char const *argv[])
{   
    // 1690 -> 2123366400
    cout<<nthUglyNumber(24)<<endl;
    cout<<nthUglyNumber1(24)<<endl;
    return 0;
}
