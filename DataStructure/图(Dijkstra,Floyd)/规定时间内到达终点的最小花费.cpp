/*
一个国家有 n 个城市，城市编号为 0 到 n - 1 ，题目保证 所有城市 都由双向道路 连接在一起 。
    道路由二维整数数组 edges 表示，其中 edges[i] = [xi, yi, timei] 表示城市 xi 和 yi 
    之间有一条双向道路，耗费时间为 timei 分钟。两个城市之间可能会有多条耗费时间不同的道路，
    但是不会有道路两头连接着同一座城市。

每次经过一个城市时，你需要付通行费。通行费用一个长度为 n 且下标从 0 开始的整数数组 passingFees 
    表示，其中 passingFees[j] 是你经过城市 j 需要支付的费用。

一开始，你在城市 0 ，你想要在 maxTime 分钟以内 （包含 maxTime 分钟）到达城市 n - 1 。旅行的 
    费用 为你经过的所有城市 通行费之和 （包括 起点和终点城市的通行费）。

给你 maxTime，edges 和 passingFees ，请你返回完成旅行的 最小费用 ，如果无法在 maxTime 
    分钟以内完成旅行，请你返回 -1 。
*/

#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(vector<int>&a, vector<int>&b){
        return a[2]>b[2];
    }
};

int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    vector<vector<pair<int, int>>>graph(n);
    for(auto e: edges){
        graph[e[0]].emplace_back(e[1], e[2]);
        graph[e[1]].emplace_back(e[0], e[2]);
    }
    vector<int>allfree(n, INT32_MAX), alltime(n, INT32_MAX);
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq;
    alltime[0] = 0, allfree[0] = passingFees[0];
    // node time free;
    pq.push({0, 0, passingFees[0]});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curNode = cur[0], curTime = cur[1], curFree = cur[2];
        
        if(curNode==n-1) return curFree;

        for(auto next: graph[curNode]){
            int nextNode = next.first, nextTime = next.second + curTime, 
                nextFree = curFree + passingFees[nextNode];
            
            if(nextTime > maxTime) continue;
            
            if(nextTime<alltime[nextNode]||nextFree<allfree[nextNode]){
                alltime[nextNode] = nextTime;
                allfree[nextNode] = nextFree;
                pq.push({nextNode, nextTime, nextFree});
            }
        }
    }
    return -1;
}


// dp 类似上题
static constexpr int INF = INT32_MAX/2;
vector<vector<int>> memo;
int dp(int maxTime, vector<vector<pair<int, int>>>& graph, vector<int>& passingFees, int time, int s){
    if(time>maxTime) return -1;
    if(s==0) return passingFees[s];
    if(memo[s][time]!=INF) return memo[s][time];
    int res = INF;
    if(graph[s].size()){
        for(auto g: graph[s]){
            int from = g.first, costtime = g.second;
            int subcost = dp(maxTime, graph, passingFees, time+costtime, from);
            if(subcost!=-1) res = min(res, passingFees[s]+subcost);
        }
    }
    memo[s][time] = res==INF ? -1:res;
    return memo[s][time];
} 

int minCost1(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    memo.resize(n, vector<int>(maxTime+1, INF));
    vector<vector<pair<int, int>>> graph(n);
    // 注意该题类似无向图，没有像航班指定方向
    for(auto e: edges) {
        graph[e[1]].emplace_back(e[0], e[2]);
        graph[e[0]].emplace_back(e[1], e[2]);
    }
    return dp(maxTime, graph, passingFees, 0, n-1);
}

// Bellman-Ford
static constexpr int INFTY = INT32_MAX / 2;
int minCost2(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
    int n = passingFees.size();
    vector<vector<int>> f(maxTime + 1, vector<int>(n, INFTY));
    f[0][0] = passingFees[0];
    for (int t = 1; t <= maxTime; ++t) {
        for (const auto& edge: edges) {
            int i = edge[0], j = edge[1], cost = edge[2];
            if (cost <= t) {
                f[t][i] = min(f[t][i], f[t - cost][j] + passingFees[i]);
                f[t][j] = min(f[t][j], f[t - cost][i] + passingFees[j]);
            }
        }
    }

    int ans = INFTY;
    for (int t = 1; t <= maxTime; ++t) {
        ans = min(ans, f[t][n - 1]);
    }
    return ans == INFTY ? -1 : ans;
}