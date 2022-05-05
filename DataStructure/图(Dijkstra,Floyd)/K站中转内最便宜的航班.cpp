/*
有 n 个城市通过一些航班连接。给你一个数组 flights ，其中 flights[i] = [fromi, toi, pricei] ，
    表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。

现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，
    你的任务是找到出一条最多经过 k 站中转的路线，使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 
    如果不存在这样的路线，则输出 -1。
*/
#include<vector>
#include<iostream>
#include<queue>
using namespace std;

struct cmp{
    bool operator()(vector<int>&a, vector<int>&b){
        return a[1]>b[1];
    }
};

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    ++k; // 
    vector<vector<vector<int>>>graph(n);
    for(auto f: flights) graph[f[0]].push_back({f[1], f[2], 0});

    vector<int> alldis(n, INT32_MAX), allcnt(n, INT32_MAX);
    alldis[src] = 0, allcnt[src] = 0;
    priority_queue<vector<int>, vector<vector<int>>, cmp>pq;
    pq.push({src, 0, 0});

    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int curNode = cur[0], curDist = cur[1], curCnt = cur[2];
        // 到终点了
        if(curNode==dst) return curDist;
        // 已经大于最小中转站的个数了
        if(curCnt>=k) continue;
        for(auto next: graph[curNode]){
            int nextNode = next[0], nextDist = next[1] + curDist, nextCnt = curCnt+1;
            if(nextDist<alldis[nextNode]){
                alldis[nextNode] = nextDist;
                allcnt[nextNode] = nextCnt;
            }
            // 减枝, 如果中转次数更多，花费还更大，那必然不会是最短路径
            if(nextDist>alldis[nextNode] && nextCnt>allcnt[nextNode]){
                continue;
            }
            pq.push({nextNode, nextDist, nextCnt});
        }

    }
    return -1;
}

// dp
vector<vector<int>>memo;
int dp(vector<vector<pair<int, int>>>& graph, int k, int src, int dst){
    // 等于最开始的位置 返回 花费 0
    if(dst==src) return 0;
    // 中转站次数用完
    if(k==0) return -1;
    // 之前遇到
    if(memo[k][dst]!=INF) return memo[k][dst];
    
    int res = INT32_MAX;
    // 当该节点有入度时
    if(graph[dst].size()){
        // 遍历入度节点
        for(auto pre: graph[dst]){
            int from = pre.first, cost = pre.second;
            int subcost = dp(graph, k-1, src, from);
            // 跳过无解的情况
            if(subcost!=-1) res = min(subcost + cost, res);
        }   
    }
    memo[k][dst] = res == INT32_MAX ? -1 : res;

    return memo[k][dst];
}


int findCheapestPrice1(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    ++k;
    memo.resize(k+1, vector<int>(n, INF));
    vector<vector<pair<int, int>>>graph(n);
    // 有向图, 类似 入度出度 , 记录每个节点的入度 to = f[1], from = f[0];
    for(auto f: flights) graph[f[1]].emplace_back(f[0], f[2]);
    return dp(graph, k, src, dst);
}


// Bellman-Ford
static constexpr int INF = 10000 * 101 + 1;
int findCheapestPrice2(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<int>> f(k + 2, vector<int>(n, INF));
    f[0][src] = 0;
    for (int t = 1; t <= k + 1; ++t) {
        for (auto&& flight: flights) {
            int j = flight[0], i = flight[1], cost = flight[2];
            f[t][i] = min(f[t][i], f[t - 1][j] + cost);
        }
    }
    int ans = INF;
    for (int t = 1; t <= k + 1; ++t) {
        ans = min(ans, f[t][dst]);
    }
    return (ans == INF ? -1 : ans);
}

int main(int argc, char const *argv[])
{
    // vector<vector<int>>graph;
    return 0;
}
